

#include "GladiatorGame.h"
#include "AGladiatorCode.h"


AAGladiatorCode::AAGladiatorCode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void	AAGladiatorCode::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hello World!"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::FromInt(life));
	}
}

