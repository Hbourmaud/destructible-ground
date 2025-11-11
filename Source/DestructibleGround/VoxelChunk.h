#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "VoxelChunk.generated.h"

UCLASS()
class DESTRUCTIBLEGROUND_API AVoxelChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	AVoxelChunk();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ProcMesh;

	static const int32 ChunkSize = 32;
	static const float VoxelSize;

	TArray<float> Densities;

	void GenerateDensityField();
	void GenerateMesh();

	FVector VertexInterp(const FVector& P1, const FVector& P2, float Val1, float Val2) const;

	float Perlin3D(float x, float y, float z);
};
