

#include "GladiatorGame.h"
#include "AGladiatorCode.h"


AAGladiatorCode::AAGladiatorCode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(true);
	canAttack = true;
	timeToAttack = 2.0f;
}

void
AAGladiatorCode::Tick(float deltaseconds)
{
	Super::Tick(deltaseconds);
}

void
AAGladiatorCode::setID(int32 pID)
{
	pId = pID;
}