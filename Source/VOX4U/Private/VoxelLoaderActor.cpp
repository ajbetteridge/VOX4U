// Copyright 2016-2018 mik14a / Admix Network. All Rights Reserved.

#include "VoxelLoaderActor.h"
#include "VoxelLoaderComponent.h"

AVoxelLoaderActor::AVoxelLoaderActor(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	VoxelComponent = CreateDefaultSubobject<UVoxelLoaderComponent>("VoxelComponent");
	VoxelComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

UVoxelLoaderComponent* AVoxelLoaderActor::GetVoxelComponent() const
{
	return VoxelComponent;
}
