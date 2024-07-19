// Copyright 2017 Daniel Orchard. All Rights Reserved.

#include "GridsCore.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFile.h"
//#include "HAL/PlatformFilemanager.h"
//#include "Runtime/Core/Public/Containers/Algo/Reverse.h"


UGridsCore::UGridsCore(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

//----------------------------//
// Checks
//----------------------------//

bool UGridsCore::IsOddFloat(const float A)
{
	int x = int(floorf(A));
	return (x & 1) > 0;
}

bool UGridsCore::IsOddInt(const int A)
{
	return (A & 1) > 0;
}

// -----------------------------------------------------------//
// Converters
// -----------------------------------------------------------//

FVector UGridsCore::Conv_OffsetToCube(FOffsetCoords Offset)
{
	float x = int(Offset.Col - (Offset.Row - (1 * (Offset.Row & 1))) / 2);
	float y = -x - Offset.Row;
	float z = Offset.Row;
	return FVector(x, y, z);
}

FOffsetCoords UGridsCore::Conv_CubeToOffset(FVector Cube)
{
	int Z = int(Cube.Z);
	int Col = Cube.X + (Z - (1 * (Z & 1))) / 2;
	int Row = Cube.Z;
	return FOffsetCoords(Col,Row);
}

TArray<FOffsetCoords> UGridsCore::Conv_CubeArrayToOffsetArray(TArray<FVector> CubeArray)
{
	TArray<FOffsetCoords> x = {};
	for (auto& i : CubeArray)
	{
		x.Emplace(Conv_CubeToOffset(i));
	}
	return x;
}

TArray<FVector> UGridsCore::Conv_OffsetArrayToCubeArray(TArray<FOffsetCoords> OffsetArray)
{
	TArray<FVector> x;
	for (auto& i : OffsetArray)
		{
			x.Emplace(Conv_OffsetToCube(i));
		}
	return x;
}

FVector2D UGridsCore::Conv_OffsetToVector2D(FOffsetCoords Offset)
{
	return FVector2D(float(Offset.Row), float(Offset.Col));
}

FOffsetCoords UGridsCore::Conv_Vector2DToOffsetCoords(FVector2D Vector)
{
	return FOffsetCoords(Vector.Y, Vector.X);
}

TArray<FVector2D> UGridsCore::Conv_OffsetArrayToVector2DArray(TArray<FOffsetCoords> OffsetArray)
{
	TArray<FVector2D> x;
	for (auto& i : OffsetArray)
	{
		x.Emplace(Conv_OffsetToVector2D(i));
	}
	return x;
}

TArray<FOffsetCoords> UGridsCore::Conv_Vector2DArrayToOffsetArray(TArray<FVector2D> Vector2DArray)
{
	TArray<FOffsetCoords> x;
	for (auto& i : Vector2DArray)
	{
		x.Emplace(Conv_Vector2DToOffsetCoords(i));
	}
	return x;
}

TArray<FOffsetCoords> UGridsCore::Conv_VisitedNodesToOffsetArray(TArray<FVisitedNode> VisitedNodes)
{
	TArray<FOffsetCoords> x;
	for (auto& i : VisitedNodes)
	{
		x.Emplace(i.PreviousNode);
	}
	return x;
}

FVector UGridsCore::Conv_OffsetToVector(FOffsetCoords A, float Z)
{
	return FVector(float(A.Row), float(A.Col), Z);
}


// -----------------------------------------------------------//
// Misc
// -----------------------------------------------------------//

FVector UGridsCore::InvertVector(FVector InA)
{
	return InA * -1;
}

TArray<FString> UGridsCore::FindAllSaveFiles()
{
	
	// Create a new visitor class

	class FFindSavesVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:
		FFindSavesVisitor() {}
		TArray<FString> SavesFound;
		virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory)
		{
			
			if (!bIsDirectory)
			{
				FString FullFilePath(FilenameOrDirectory);

				if (FPaths::GetExtension(FullFilePath) == TEXT("sav"))
				{
					FString CleanFilename = FPaths::GetBaseFilename(FullFilePath, true);
					//CleanFilename = CleanFilename.Replace
					SavesFound.Add(CleanFilename);
				}
			}
			return true;
		}
	};

	TArray<FString> Saves;
	const FString SaveDirectory = FPaths::ProjectSavedDir() + TEXT("SaveGames");

	FFindSavesVisitor Visitor;

	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*SaveDirectory, Visitor);
	Saves = Visitor.SavesFound;

	return Saves;
}


