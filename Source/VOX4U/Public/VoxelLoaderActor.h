// Copyright 2016-2018 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include <GameFramework/Actor.h>
#include "VoxelLoaderActor.generated.h"

class UVoxelLoaderComponent;

UCLASS()
class VOX4U_API AVoxelLoaderActor : public AActor
{
	GENERATED_BODY()

	AVoxelLoaderActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:

	UVoxelLoaderComponent* GetVoxelComponent() const;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = VoxelActor)
	UVoxelLoaderComponent* VoxelComponent;

};
