// Copyright 2016-2018 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include <ThumbnailHelpers.h>
#include <ThumbnailRendering/DefaultSizedThumbnailRenderer.h>
#include "VoxelThumbnailRenderer.generated.h"

class AVoxelLoaderActor;
class UVoxelLoader;

class FVoxelThumbnailScene : public FThumbnailPreviewScene
{
public:

	FVoxelThumbnailScene();

	void SetVoxel(UVoxelLoader* Voxel);

protected:

	virtual void GetViewMatrixParameters(const float InFOVDegrees, FVector& OutOrigin, float& OutOrbitPitch, float& OutOrbitYaw, float& OutOrbitZoom) const override;

private:

	AVoxelLoaderActor* Actor;

};

/**
 * Voxel asset thumbnail renderer
 */
UCLASS()
class UVoxelThumbnailRenderer : public UDefaultSizedThumbnailRenderer
{
	GENERATED_BODY()
	
public:

	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* Viewport, FCanvas* Canvas) override;

private:

	TMap<UVoxelLoader*, FVoxelThumbnailScene*> ThumbnailScenes;

};
