// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tile.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileSpawner.generated.h"

UCLASS()
class INFLUENCEMAPPING_API ATileSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileSpawner();

	UPROPERTY(VisibleAnywhere)
	ATile* baseTile;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
