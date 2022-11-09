// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#define SIZE 16
#include <vector>
#include <iostream>
using namespace std;
#include "Tile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InfluenceMap.generated.h"

UCLASS()
class INFLUENCEMAPPING_API AInfluenceMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInfluenceMap();
	AInfluenceMap(ATile* map[SIZE][SIZE]);
	//AInfluenceMap(std::vector<std::vector<ATile*>> *t_map);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//std::vector<std::vector<ATile*>> *map;
	ATile* map[SIZE][SIZE];

	//static ConstructorHelpers::FObjectFinder <UMaterialInterface>Material_Blue(TEXT("Material'/Game/Materials/M_Basic_Wall_red.M_Basic_Wall_red'"));

	struct Location {

		Location(int _x, int _y)
		{
			x = _x;
			y = _y;
		}
		float x;
		float y;
	};

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float linearInfluence(float maxValue, float distance, float maxDistance);
	float calculateDistance(Location a, Location b);
	void calculateInfluence(Location center, float maxValue, float maxDistance, ATile* t_map[SIZE][SIZE]);
	void colorMap(ATile* t_map[SIZE][SIZE]);
	void Process(ATile* map[SIZE][SIZE]);
};
