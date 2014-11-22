

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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Attack)
	bool	canAttack;
	UPROPERTY(EditAnywhere, Category = Attack)
	float	timeToAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerID)
	int32	pId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DefaultPosition)
	FVector	moveDir;

	virtual void	Tick(float) OVERRIDE;

public:
	void	setID(int32);
};
