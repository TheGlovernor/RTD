// Copyright 2017 Daniel Orchard. All Rights Reserved.

#pragma once
#include "HexGrids.h"
#include "OffsetCoords.generated.h"

// Core struct for working with grids. 
USTRUCT(BlueprintType)
struct FOffsetCoords
{
	
public:
	GENERATED_BODY()
	
	/** OffsetCoords Column, or Y component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grids")
	int Col;
	
	/** OffsetCoords Row, or X component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grids")
	int Row;

	/** Grid 0,0 */
	static HEXGRIDS_API const FOffsetCoords ZeroCoord;

	/** Default constructor (no initialization). */
	FORCEINLINE FOffsetCoords();

	/**
	* Constructor using initial values for each component.
	*
	* @param InCol Y Coordinate.
	* @param InRow X Coordinate.
	*/
	FORCEINLINE FOffsetCoords(int InCol, int InRow);

	/**
	* Constructor initializing all components to a single Integer value.
	*
	* @param InI Value to set all components to.
	*/
	explicit FORCEINLINE FOffsetCoords(int InI);

	/**
	* Constructor initializing all components to a single float value.
	*
	* @param InF Value to set all components to.
	*/
	explicit FORCEINLINE FOffsetCoords(float InF);

	/**
	* Constructs a OffsetCoord from an FVector2D.
	*
	* @param V Vector to copy from.
	* @param InZ Z Coordinate.
	*/
	explicit FORCEINLINE FOffsetCoords(FVector2D V);

	// Inline Operators

	FORCEINLINE bool operator==(const FOffsetCoords& V) const;
	
	FORCEINLINE bool operator!=(const FOffsetCoords& V) const;

	FORCEINLINE FOffsetCoords operator*(float Scale) const;

	FORCEINLINE FOffsetCoords operator*(int Scale) const;

	FORCEINLINE FOffsetCoords operator*(FVector2D V) const;

	FORCEINLINE FOffsetCoords operator*(FOffsetCoords Scale) const;

	FORCEINLINE FOffsetCoords operator-(FOffsetCoords& V) const;

	FORCEINLINE FOffsetCoords operator-(float V) const;

	FORCEINLINE FOffsetCoords operator-(int V) const;

	FORCEINLINE FOffsetCoords operator/(float Scale) const;

	FORCEINLINE FOffsetCoords operator/(int Scale) const;

	FORCEINLINE FOffsetCoords operator+(FOffsetCoords& V) const;

	FORCEINLINE FOffsetCoords operator+(const int InI) const;

	FORCEINLINE FOffsetCoords operator+(const float InF) const;

	FORCEINLINE FOffsetCoords operator+(const FVector2D& V) const;

	// Functions

	bool isZero() const;

	bool InitFromString(const FString& InSourceString);

};

// Init

FORCEINLINE FOffsetCoords::FOffsetCoords()
{}

FORCEINLINE FOffsetCoords::FOffsetCoords(int InCol, int InRow)
	: Col(InCol), Row(InRow)
{}

FORCEINLINE FOffsetCoords::FOffsetCoords(int InI)
	: Col(InI), Row(InI)
{}

FORCEINLINE FOffsetCoords::FOffsetCoords(float InF)
	: Col(int(InF)), Row(int(InF))
{}

FORCEINLINE FOffsetCoords::FOffsetCoords(FVector2D V)
	: Col(V.Y), Row(V.X)
{}

FORCEINLINE uint32 GetTypeHash(const FOffsetCoords& V)
{
	return FCrc::MemCrc_DEPRECATED(&V, sizeof(FOffsetCoords));
}

FORCEINLINE bool FOffsetCoords::operator==(const FOffsetCoords& V) const
{
	return Col == V.Col && Row == V.Row;
}

FORCEINLINE bool FOffsetCoords::operator!=(const FOffsetCoords& V) const
{
	return Col != V.Col || Row != V.Row;
};

FORCEINLINE FOffsetCoords FOffsetCoords::operator*(float Scale) const
{
	return FOffsetCoords(Col * Scale, Row * Scale);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator*(int Scale) const
{
	return FOffsetCoords(Col * Scale, Row * Scale);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator*(FOffsetCoords Scale) const
{
	return FOffsetCoords(Col * Scale.Col, Row * Scale.Row);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator-(FOffsetCoords& V) const
{
	return FOffsetCoords(Col - V.Col, Row - V.Row);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator-(float V) const
{
	return FOffsetCoords(Col - V, Row - V);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator-(int V) const
{
	return FOffsetCoords(Col - V, Row - V);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator/(float Scale) const
{
	return FOffsetCoords(Col * Scale, Row * Scale);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator/(int Scale) const
{
	return FOffsetCoords(Col * Scale, Row * Scale);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator+(FOffsetCoords& V) const
{
	return FOffsetCoords(Col + V.Col, Row + V.Row);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator+(const int InI) const
{
	return FOffsetCoords(Col + InI, Row + InI);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator+(const float InF) const
{
	return FOffsetCoords(Col + InF, Row + InF);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator+(const FVector2D& V) const
{
	return FOffsetCoords(Col + V.Y, Row + V.X);
}

FORCEINLINE FOffsetCoords FOffsetCoords::operator*(FVector2D V) const
{
	return FOffsetCoords(Col * V.Y, Row * V.X);
}

FORCEINLINE bool FOffsetCoords::isZero() const
{
	return Col == 0 && Row == 0;
}

FORCEINLINE bool FOffsetCoords::InitFromString(const FString& InSourceString)
{
	Col = Row = 0;

	const bool C = FParse::Value(*InSourceString, TEXT("Col="), Col);
	const bool R = FParse::Value(*InSourceString, TEXT("Row="), Row);

	const bool bSuccessful = C && R;
	return bSuccessful;
}
