// copyrite an4l beads netw0rk 2017 we plug em we love em

#include "Testing_Grounds.h"
#include "Grabber.h"

#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogTemp,Warning, TEXT("ASS HAt REPORTING FOR DUTY!!"))
	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	//UE_LOG(LogTemp, Warning, TEXT("%s"), *PlayerViewPointRotation.ToString())
	//	UE_LOG(LogTemp, Warning, TEXT("%s"), *(PlayerViewPointRotation.Vector()).ToString())
	//	UE_LOG(LogTemp, Warning, TEXT("  "))
		// ...
		FVector PlayerDirection = PlayerViewPointRotation.Vector();
		FVector LineTraceEnd = (PlayerViewPointLocation + PlayerDirection*Reach);
		DrawDebugLine(GetWorld(), PlayerViewPointLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.f, 1.0f, 50.0f);

}

