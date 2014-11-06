

#include "GladiatorGame.h"
#include "IADirector.h"


AIADirector::AIADirector(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void	AIADirector::BeginPlay()
{
	Super::BeginPlay();
	for (int32 index = 0; index < SpawnPointList.Num(); index++)
	{
		FVector	lVector = SpawnPointList[index]->GetActorLocation();
		FRotator	lRotator = SpawnPointList[index]->GetActorRotation();
		GetWorld()->SpawnActor(SpawnClass, &lVector, &lRotator);
	}
}
