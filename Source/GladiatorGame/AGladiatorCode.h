

#pragma once

#include "GameFramework/Character.h"
#include "AGladiatorCode.generated.h"

/**
 * 
 */
UCLASS()
class GLADIATORGAME_API AAGladiatorCode : public ACharacter
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Power)
	int32	life;

	virtual void	BeginPlay() override;
};
