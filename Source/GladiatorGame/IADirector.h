

#pragma once

#include "GameFramework/Actor.h"
#include "IADirector.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORGAME_API AIADirector : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Target)
	TArray<ATargetPoint*>	SpawnPointList;
	UPROPERTY(EditAnywhere, noclear, BlueprintReadWrite, Category = Target)
	TSubclassOf<class AActor>  SpawnClass;
	
	virtual void	BeginPlay() override;
};
