// Fill out your copyright notice in the Description page of Project Settings.

#include "TileTypeGen.h"
#include <cmath>

UTileTypeGen::UTileTypeGen() {}

void UTileTypeGen::clearMap() {
	typeMap = TMap<FOffsetCoords, ETileTypes>{};
}

//void UTileTypeGen::initMap(int p, int s, UFastNoiseWrapper* FNW) {
//	init(s, p);
//}

TArray<FOffsetCoords> UTileTypeGen::getNs(FOffsetCoords c) {
	TArray<FOffsetCoords> temp;
	for (FVector v : UGridsHex::GetHexNeighbours(c)) {
		temp.Add(UGridsCore::Conv_CubeToOffset(v));
	}
	return temp;
}

TArray<FOffsetCoords> UTileTypeGen::getPathableNs(FOffsetCoords c) {
	FOffsetCoords tempc;
	TArray<FOffsetCoords> allN;
	TArray<FOffsetCoords> pathableN;

	// Get All Neighbors
	for (FVector v : UGridsHex::GetHexNeighbours(c)) {
		allN.Add(CtoO(v));
	}

	//check if neighbors can be a path
	for (FOffsetCoords c2 : allN) {
		tempc = c2;
		if (canBePath(tempc)) {
			pathableN.Add(tempc);
		}
	}

	return pathableN;
}

int UTileTypeGen::getx(FOffsetCoords c) {
	return c.Col;
}

int UTileTypeGen::gety(FOffsetCoords c) {
	return c.Row;
}

FOffsetCoords UTileTypeGen::CtoO(FVector v) {
	return UGridsCore::Conv_CubeToOffset(v);
}

FVector UTileTypeGen::OtoC(FOffsetCoords c) {
	return UGridsCore::Conv_OffsetToCube(c);
}

ETileTypes UTileTypeGen::getType(FOffsetCoords c) {
	return typeMap[c];
}

int UTileTypeGen::randIndex(int arrLen) {
	if (arrLen == 0) {
		return -1;
	}
	return rand() % arrLen;
}

bool UTileTypeGen::canBePath(FOffsetCoords c) {
	int count = 0;
	
	if (typeMap.Contains(c)) {
		if (typeMap[c] == ETileTypes::Tile_Home || typeMap[c] == ETileTypes::Tile_Gate || typeMap[c] == ETileTypes::Tile_Path || typeMap[c] == ETileTypes::Tile_PathHead || typeMap[c] == ETileTypes::Tile_Portal) {
			count = 2;
		}
	}

	for (FVector v : UGridsHex::GetHexNeighbours(c)) {
		FOffsetCoords tempc = CtoO(v);
		if (typeMap.Contains(tempc)) {
			if (typeMap[tempc] == ETileTypes::Tile_Path || typeMap[tempc] == ETileTypes::Tile_PathHead || typeMap[tempc] == ETileTypes::Tile_Gate || typeMap[tempc] == ETileTypes::Tile_Home || typeMap[tempc] == ETileTypes::Tile_Portal) {
				count++;
			}
			else if (typeMap[tempc] == ETileTypes::Tile_Home) {
				count = 2;
			}
		}
	}

	return count == 1;
}

FOffsetCoords UTileTypeGen::makePortal(FOffsetCoords c) {
	TArray<FOffsetCoords> ring;
	bool checking = true;
	UE_LOG(LogTemp, Warning, TEXT("trying to draw portal"));

	UGridsHex::SingleRing(c, 15, ring);
	for (FOffsetCoords rc : ring) {
		checking = true;
		TArray<FOffsetCoords> pring;
		UE_LOG(LogTemp, Warning, TEXT("checking ring"));
		UGridsHex::MovementRange(rc, 3, pring);
		while (checking) {
			for (FOffsetCoords prc : pring) {
				UE_LOG(LogTemp, Warning, TEXT("checking pring"));
				if (typeMap.Contains(prc)) {
					UE_LOG(LogTemp, Warning, TEXT("nope"));
					checking = false;
				}
			}
			// portal good
			UE_LOG(LogTemp, Warning, TEXT("building portal"));
			typeMap.Add(rc, ETileTypes::Tile_Portal);
			TArray<FOffsetCoords> portalNs = getNs(rc);
			FOffsetCoords headC = portalNs[randIndex(portalNs.Num())];
			typeMap.Add(headC, ETileTypes::Tile_PathHead);
			//headMap.Emplace(headC, ETileTypes::Tile_PathHead);
			return(headC);
		}
	}

	return origin;

}

void UTileTypeGen::init(int s, int p) {
	seed = s;
	srand(s);
	if (p <= 1) {
		paths = 1;
	}
	else if (p >= 3) {
		paths = 3;
	}
	else {
		paths = 2;
	}

	initCostMap(origin);
	initPaths(paths);

	for (int i = 0; i < 5; i++) {
		TSet<FOffsetCoords> temp = headMap;
		for (FOffsetCoords c : temp) {
			buildPath(c);
		}
	}
}

/*
* set costs around center
*/
void UTileTypeGen::initCostMap(FOffsetCoords center) {
	for (int i = -100; i < 100; i++) {
		for (int j = -100; j < 100; j++) {
			costMap.Add(FOffsetCoords(i,j) + center, 1);
			grid.Add(FOffsetCoords(i, j));
		}
	}
}

// Builds initial paths from base, could use a rewrite to be prettier
void UTileTypeGen::initPaths(int p) {
	typeMap.Add(origin, ETileTypes::Tile_Home);
	blockedToPath.Add(origin);

	//57356

	// build gates and paths
	if (p <= 1) {
		int index = randIndex(6);
		TArray<FOffsetCoords> n = getNs(origin);
		ETileTypes type = ETileTypes::Tile_Gate;
		for (int i = 0; i < 3; i++) {
			FOffsetCoords toAdd = nextHexInDirection(n[index], origin, i);
			typeMap.Add(toAdd, type);
			blockedToPath.Add(toAdd);
			type = ETileTypes::Tile_Path;
			if (i != 2) {
				blockNs(toAdd);
			}
			else {
				headMap.Add(toAdd);
			}
		}
	}
	else if (p == 2) {
		int index = randIndex(6);
		TArray<FOffsetCoords> n = getNs(origin);
		ETileTypes type = ETileTypes::Tile_Gate;
		for (int i = 0; i < 3; i++) {
			FOffsetCoords toAdd = nextHexInDirection(n[index], origin, i);
			typeMap.Add(toAdd, type);
			blockedToPath.Add(toAdd);
			type = ETileTypes::Tile_Path;
			if (i != 2) {
				blockNs(toAdd);
			}
			else {
				headMap.Add(toAdd);
			}
		}
		index = randIndex(3);
		n = getPathableNs(origin);
		type = ETileTypes::Tile_Gate;
		for (int i = 0; i < 3; i++) {
			FOffsetCoords toAdd = nextHexInDirection(n[index], origin, i);
			typeMap.Add(toAdd, type);
			blockedToPath.Add(toAdd);
			type = ETileTypes::Tile_Path;
			if (i != 2) {
				blockNs(toAdd);
			}
			else {
				headMap.Add(toAdd);
			}
		}
	}
	else if (p >= 3) {
		int index = randIndex(2);
		TArray<FOffsetCoords> n = getNs(origin);
		for (int i = 0; i < 3; i++) {
			FOffsetCoords toAdd = nextHexInDirection(n[index + (i * 2) ], origin, 0);
			typeMap.Add(toAdd, ETileTypes::Tile_Gate);
			blockedToPath.Add(toAdd);
			blockNs(toAdd);
			toAdd = nextHexInDirection(n[index + (i * 2)], origin, 1);
			typeMap.Add(toAdd, ETileTypes::Tile_Path);
			blockedToPath.Add(toAdd);
			blockNs(toAdd);
			toAdd = nextHexInDirection(n[index + (i * 2)], origin, 2);
			typeMap.Add(toAdd, ETileTypes::Tile_Path);
			blockedToPath.Add(toAdd);
			headMap.Add(toAdd);
		}
	}

	//build walls
	for (FOffsetCoords c : getNs(origin)) {
		if (!typeMap.Contains(c)) {
			typeMap.Add(c, ETileTypes::Tile_Wall);
			blockedToPath.Add(c);
		}
	}
}

FOffsetCoords UTileTypeGen::nextHexInDirection(FOffsetCoords to, FOffsetCoords from, int distance = 0) {
	FVector t = OtoC(to);
	FVector f = OtoC(from);
	FVector diff = (t - f) * distance;
	t = t + diff;
	return CtoO(t);
}

void UTileTypeGen::blockNs(FOffsetCoords c) {
	for (FOffsetCoords tb : getNs(c)) {
		blockedToPath.Add(tb);
	}
}

void UTileTypeGen::buildPath(FOffsetCoords c) {
	FOffsetCoords head = c;
		// choose coord from ring
		TArray<FOffsetCoords> ring;
		UGridsHex::SingleRing(head, 6, ring);
		FOffsetCoords target = ring[randIndex(ring.Num())];
		// a* pathfind to target
		TArray<FVector> results;
		bool succ;
		UGridsHex::AStarPathfinding(c, target, grid, costMap, blockedToPath, origin, true, false, succ, results);
		
		// draw 3 tiles
		if (results.Num() < 2) {
			FOffsetCoords toAdd = CtoO(results[0]);
			typeMap.Add(toAdd, ETileTypes::Tile_Portal);
		} else {
			for (int j = 0; j < 4; j++) {
				FOffsetCoords toAdd = CtoO(results[j]);
				typeMap.Add(toAdd, ETileTypes::Tile_Path);
				if (j < 3) {
					blockNs(toAdd);
				}
				else if (j == 3) {
					headMap.Add(toAdd);
				}
			}
		}
	headMap.Remove(c);
}

int UTileTypeGen::min(int x, int y) {
	if (y < x) {
		return y;
	}
	else return x;
}

int UTileTypeGen::max(int x, int y) {
	if (y > x) {
		return y;
	}
	else return x;
}