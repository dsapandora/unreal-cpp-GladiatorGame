

#pragma once

#include <vector>
#include "AGladiatorCode.h"

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
	TSubclassOf<class AAGladiatorCode>  SpawnClass;

	virtual void	BeginPlay() OVERRIDE;
	virtual void	Tick(float) OVERRIDE;
	
private:
	std::vector<AActor*>	vm_enemyList;
	std::vector<FVector>	vm_defaultDir;
	float					vm_secondsLeft;
	int						vm_playerCanAttack;
};
