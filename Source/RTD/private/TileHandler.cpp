// Fill out your copyright notice in the Description page of Project Settings.


#include "TileHandler.h"

UTileHandler::UTileHandler() {}

void UTileHandler::init(int s, int p) {
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
}

void UTileHandler::initCostMap(FOffsetCoords center) {
	for (int i = -100; i < 100; i++) {
		for (int j = -100; j < 100; j++) {
			costMap.Add(FOffsetCoords(i, j) + center, 1);
			grid.Add(FOffsetCoords(i, j));
		}
	}
}

void UTileHandler::initPaths(int p) {

	pathMap.Add(origin, ETileTypes2::player_base);
	blockedToPathing.Add(origin);

	if (p <= 1) {
		int index = randIndex(6);
		TArray<FOffsetCoords> n = nbrs(origin);
		for (int i = 1; i < 4; i++) {
			pathMap.Add(n[index] * i);
			blockedToPathing.Add(n[index] * i);
		}
	}
	else if (p == 2) {
		int index = randIndex(6);
		TArray<FOffsetCoords> n = nbrs(origin);
		for (int i = 1; i < 4; i++) {
			pathMap.Add(n[index] * i);
			blockedToPathing.Add(n[index] * i);
		}
		index = randIndex(3);
		n = nbrs(origin);
		for (int i = 1; i < 4; i++) {
			pathMap.Add(n[index] * i);
			blockedToPathing.Add(n[index] * i);
		}
	}
	else if (p >= 3) {
		int index = randIndex(2);
		TArray<FOffsetCoords> n = nbrs(origin);
		for (int i = 0; i < 3; i++) {
			pathMap.Add(n[index + (i * 2)]);
			blockedToPathing.Add(n[index + (i * 2)]);
			pathMap.Add(n[index + (i * 2)] * 2);
			blockedToPathing.Add(n[index + (i * 2)] * 2);
			pathMap.Add(n[index + (i * 2)] * 3);
			blockedToPathing.Add(n[index + (i * 2)] * 3);
		}
	}



	//build gates
	for (int i = 0; i < paths; i++) {

		int maxChoice = 6 / paths; //at 1 max = 6; 2 max = 3; 3 max = 2;
		TArray<FOffsetCoords> homeNs = nbrs(origin);

		// choose a neighbor from homNs from min of max choice and array size
		int index = randIndex(min(maxChoice, homeNs.Num()));

		if (paths != 3) {
			pathMap.Add(homeNs[index], ETileTypes2::player_gate);
			blockedToPathing.Add(homeNs[index]);
			headMap.Add(homeNs[index]);
		}
		else {
			pathMap.Add(homeNs[index], ETileTypes2::player_gate);
			blockedToPathing.Add(homeNs[index]);
			headMap.Add(homeNs[index]);
			pathMap.Add(homeNs[index + 2], ETileTypes2::player_gate);
			blockedToPathing.Add(homeNs[index + 2]);
			headMap.Add(homeNs[index + 2]);
			pathMap.Add(homeNs[index + 4], ETileTypes2::player_gate);
			blockedToPathing.Add(homeNs[index + 4]);
			headMap.Add(homeNs[index + 4]);
			i = paths;
		}
	}


	//build walls
	for (FOffsetCoords c : nbrs(origin)) {
		if (!pathMap.Contains(c)) {
			pathMap.Add(c, ETileTypes2::player_wall);
			blockedToPathing.Add(c);
		}
	}

}

TArray<FOffsetCoords> UTileHandler::nbrs(FOffsetCoords c) {
	TArray<FOffsetCoords> temp;
	for (FVector v : UGridsHex::GetHexNeighbours(c)) {
		temp.Add(UGridsCore::Conv_CubeToOffset(v));
	}
	return temp;
}

TArray<FOffsetCoords> UTileHandler::pnbrs(FOffsetCoords c) {
	TArray<FOffsetCoords> temp;
	for (FVector v : UGridsHex::GetHexNeighbours(c)) {
		temp.Add(UGridsCore::Conv_CubeToOffset(v));
	}
	for (FOffsetCoords pn : temp) {
		int count = 0;
		for (FOffsetCoords nn : nbrs(pn)) {
			if (pathMap.Contains(nn)) {
				if (pathMap[nn] == ETileTypes2::player_base || pathMap[nn] == ETileTypes2::player_gate || pathMap[nn] == ETileTypes2::path) {
					count++;
				}
				else if (pathMap[nn] == ETileTypes2::player_base) {
					count = 2;
				}
			}
			if (count != 1) {
				temp.Remove(pn);
			}
		}
	}
	return temp;
}

FOffsetCoords UTileHandler::buildPath(FOffsetCoords o) {
	TMap<FOffsetCoords, FVisitedNode> visited;
	TArray<FOffsetCoords> pathables = UGridsHex::FloodFill(o, 3, grid, visited, blockedToPathing, costMap);
	return o;

	//to init paths, get coord, multiply by 3, build to coord

	//get array of coords in a ring around o,
	//put in order of highest abs(col + row) to lowest
	//remove some part? highest lowest mid
	//randomly choose a remaining coord
	//use a* pathfinding to the coord
	// if length a* < 3 then build what you can and place portal

}

int UTileHandler::randIndex(int arrLen) {
	if (arrLen == 0) {
		return -1;
	}
	return rand() % arrLen;
}
int UTileHandler::min(int x, int y) {
	if (x > y) {
		return y;
	}
	return x;
}
int UTileHandler::max(int x, int y) {
	if (x < y) {
		return y;
	}
	return x;
}