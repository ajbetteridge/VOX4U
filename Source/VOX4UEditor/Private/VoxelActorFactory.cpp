// Copyright 2016-2018 mik14a / Admix Network. All Rights Reserved.

#include "VoxelActorFactory.h"
#include <AssetData.h>
#include "VoxelLoader.h"
#include "VoxelLoaderActor.h"
#include "VoxelLoaderComponent.h"

UVoxelActorFactory::UVoxelActorFactory(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	DisplayName = NSLOCTEXT("VOX4U", "UVoxelActorFactory", "Voxel Actor");
	NewActorClass = AVoxelLoaderActor::StaticClass();
}

void UVoxelActorFactory::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	Super::PostSpawnActor(Asset, NewActor);

	AVoxelLoaderActor* VoxelActor = CastChecked<AVoxelLoaderActor>(NewActor);
	UVoxelLoaderComponent* VoxelComponent = VoxelActor->GetVoxelComponent();
	check(VoxelComponent);

	if (UVoxelLoader* Voxel = Cast<UVoxelLoader>(Asset)) {
		VoxelComponent->UnregisterComponent();
		VoxelComponent->SetVoxel(Voxel, true);
		VoxelComponent->RegisterComponent();
	}
	VoxelActor->PostEditChange();
}

void UVoxelActorFactory::PostCreateBlueprint(UObject* Asset, AActor* CDO)
{
	if (AVoxelLoaderActor* VoxelActor = Cast<AVoxelLoaderActor>(CDO)) {
		UVoxelLoaderComponent* VoxelComponent = VoxelActor->GetVoxelComponent();
		check(VoxelComponent);
		if (UVoxelLoader* Voxel = Cast<UVoxelLoader>(Asset)) {
			VoxelComponent->SetVoxel(Voxel, true);
		}
	}
}

bool UVoxelActorFactory::CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg)
{
	if (AssetData.IsValid()) {
		UClass* AssetClass = AssetData.GetClass();
		if (AssetClass && AssetClass->IsChildOf(UVoxelLoader::StaticClass())) {
			return true;
		} else {
			OutErrorMsg = NSLOCTEXT("VOX4U", "CanCreateActorFrom_NoVoxel", "No Voxel data specified.");
			return false;
		}
	} else {
		return true;
	}
}
