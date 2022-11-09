// Fill out your copyright notice in the Description page of Project Settings.

#include "TileSpawner.h"
#include "InfluenceMap.h"

// Sets default values
ATileSpawner::ATileSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATileSpawner::BeginPlay()
{
	Super::BeginPlay();

	//auto map = new std::vector<std::vector<ATile*>>();
	ATile* map[SIZE][SIZE];
	FVector location = FVector::ZeroVector;
	FRotator rotation = FRotator::ZeroRotator;
	float shift = 100;

	for (int i = 0; i < 16; ++i)
	{
		auto line = new std::vector<ATile*>();
		for (int j = 0; j < 16; ++j)
		{
			auto tile = (ATile*)GetWorld()->SpawnActor(ATile::StaticClass(), &location, &rotation);
			location.X += shift;
			map[i][j] = tile;
			//line->push_back(tile);
		}
		location.Y += shift;
		location.X = 0; 
		//map->push_back(*line);
	}
	auto infmap = (AInfluenceMap*)GetWorld()->SpawnActor(AInfluenceMap::StaticClass(), &location, &rotation);
	infmap->Process(map);
}

// Called every frame
void ATileSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// ....if your blueprint is in the normal project content
//TSoftClassPtr<AActor> ActorBpClass = TSoftClassPtr<AActor>(FSoftObjectPath(TEXT("Blueprint'/Game/Blueprint/BP_Floor.BP_Floor'")));

//// The actual loading
//UClass* LoadedBpAsset = ActorBpClass.LoadSynchronous();

//// (Optional, depends on how you continue using it)
//// Make sure GC doesn't steal it away from us, again
//LoadedBpAsset->AddToRoot();

//// From here on, it's business as usual, common actor spawning, just using the BP asset we loaded above
//FVector Loc = FVector::ZeroVector;
//FRotator Rot = FRotator::ZeroRotator;
//FActorSpawnParameters SpawnParams = FActorSpawnParameters();
//GetWorld()->SpawnActor(LoadedBpAsset, &Loc, &Rot, SpawnParams);