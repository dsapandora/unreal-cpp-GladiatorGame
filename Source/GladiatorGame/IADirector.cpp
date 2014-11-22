

#include "GladiatorGame.h"
#include "IADirector.h"


AIADirector::AIADirector(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(true);
	vm_secondsLeft = 0.0f;
	vm_playerCanAttack = 0;
	vm_defaultDir.push_back(FVector(0.0f, 1.0f, 0.0f));
	vm_defaultDir.push_back(FVector(-0.5f, -1.0f, 0.0f));
	vm_defaultDir.push_back(FVector(1.0f, 0.5f, 0.0f));
	vm_defaultDir.push_back(FVector(-1.0f, 0.5f, 0.0f));
	vm_defaultDir.push_back(FVector(1.0f, -1.0f, 0.0f));
}

void	AIADirector::BeginPlay()
{
	Super::BeginPlay();
	for (int32 index = 0; index < SpawnPointList.Num(); index++)
	{
		FVector	lVector = SpawnPointList[index]->GetActorLocation();
		FRotator	lRotator = SpawnPointList[index]->GetActorRotation();
		AActor*	lEnemy = GetWorld()->SpawnActor(SpawnClass, &lVector, &lRotator);
		((AAGladiatorCode*)lEnemy)->life = 3;
		((AAGladiatorCode*)lEnemy)->canAttack = false;
		((AAGladiatorCode*)lEnemy)->setID(index);
		((AAGladiatorCode*)lEnemy)->moveDir = vm_defaultDir[index];
		vm_enemyList.push_back(lEnemy);
	}
}

void
AIADirector::Tick(float deltaseconds)
{
	Super::Tick(deltaseconds);
	vm_secondsLeft += deltaseconds;
	if (vm_secondsLeft >= ((AAGladiatorCode*)vm_enemyList[vm_playerCanAttack])->timeToAttack)
	{
		((AAGladiatorCode*)vm_enemyList[vm_playerCanAttack])->canAttack = true;
		if (vm_playerCanAttack == 0)
			((AAGladiatorCode*)vm_enemyList[4])->canAttack = false;
		else
			((AAGladiatorCode*)vm_enemyList[vm_playerCanAttack - 1])->canAttack = false;
		vm_secondsLeft -= ((AAGladiatorCode*)vm_enemyList[vm_playerCanAttack])->timeToAttack;
		vm_playerCanAttack += 1;
		if (vm_playerCanAttack > 4)
			vm_playerCanAttack = 0;
	}
}