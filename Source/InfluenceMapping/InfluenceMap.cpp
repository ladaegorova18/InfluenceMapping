// Fill out your copyright notice in the Description page of Project Settings.

#include "InfluenceMap.h"
#include "Tile.h"
#include <cmath>

// Sets default values
AInfluenceMap::AInfluenceMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AInfluenceMap::AInfluenceMap(ATile* t_map[SIZE][SIZE])
{
	/*map = t_map;*/
	auto center = Location(5, 8);
	calculateInfluence(center, 1, 10, t_map);
	colorMap(t_map);
}

//AInfluenceMap::AInfluenceMap(std::vector<std::vector<ATile*>> *t_map)
//{
//	map = t_map;
//}

// Called when the game starts or when spawned
void AInfluenceMap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInfluenceMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AInfluenceMap::linearInfluence(float maxValue, float distance, float maxDistance)
{
	return maxValue - (maxValue * distance / maxDistance);
}

float AInfluenceMap::calculateDistance(Location a, Location b)
{
	float xDist = abs(a.x - b.x);
	float yDist = abs(a.y - b.y);
	return sqrt(pow(xDist, 2) + pow(yDist, 2));
}

void AInfluenceMap::calculateInfluence(Location center, float maxValue, float maxDistance, ATile* t_map[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			float dist = calculateDistance(Location(i, j), center);
			if (dist > maxDistance) continue;

			t_map[i][j]->value = linearInfluence(maxValue, dist, maxDistance);
		}
	}
}

void AInfluenceMap::colorMap(ATile* t_map[SIZE][SIZE])
{

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			float value = t_map[i][j]->value;
			UMaterialInstanceDynamic* material = UMaterialInstanceDynamic::Create(t_map[i][j]->VisualMesh->GetMaterial(0), NULL);

			material->SetVectorParameterValue(FName(TEXT("BaseColor")), FLinearColor(t_map[i][j]->value, 0, 0, 1));
			material->SetVectorParameterValue(FName(TEXT("Color")), FLinearColor(t_map[i][j]->value, 0, 0, 1));
			t_map[i][j]->VisualMesh->SetMaterial(0, material);
		}
	}
}

void AInfluenceMap::Process(ATile* t_map[SIZE][SIZE])
{
	auto center = Location(9, 8);
	calculateInfluence(center, 1, 10, t_map);
	colorMap(t_map);
}


//WorkingMap.New(MyLocation);
//WorkingMap.AddMap(EnemyLocationMap(MyLocation), 1.0f);
//WorkingMap.AddMap(AllyLocationMap(MyLocation), -0.5f);
//WorkingMap.MultiplyMap(InterestTemplate(MyLocation), 1.0f);
//Location InterestingPlace = WorkingMap.GetHighestPoint();