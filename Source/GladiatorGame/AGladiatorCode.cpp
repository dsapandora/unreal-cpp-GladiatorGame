

#include "GladiatorGame.h"
#include "AGladiatorCode.h"


AAGladiatorCode::AAGladiatorCode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(true);
	canAttack = true;
	timeToAttack = 1.0f;
}

void
AAGladiatorCode::Tick(float deltaseconds)
{
	Super::Tick(deltaseconds);
}