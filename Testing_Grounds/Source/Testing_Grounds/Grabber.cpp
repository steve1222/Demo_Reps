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
	GetPhysicsHandle();
	BindActionToGrab();
	//code will now detect if grab action is pressed, then call grab function
	
}
/// look for attached physics handle
void UGrabber::GetPhysicsHandle() {
	//
	physxHandlerComp = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	//blah
	if (physxHandlerComp) {
		UE_LOG(LogTemp, Warning, TEXT("%s: Grabber Component found."), *GetOwner()->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s: %s"), *GetOwner()->GetName(), *FString("I didnt find a physics component, meng."))
	}
}

/// look for attached input component (only appears at run time)
void UGrabber::BindActionToGrab()
{
	ownerInputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (ownerInputComponent) {
		UE_LOG(LogTemp, Warning, TEXT("%s: Input Component found."), *GetOwner()->GetName())
			// bind actions
		ownerInputComponent->BindAction("Grab Penis", IE_Pressed, this, &UGrabber::GrabPressed);
		ownerInputComponent->BindAction("Grab Penis", IE_Released, this, &UGrabber::GrabReleased);
	}
	//blah
	else {
		UE_LOG(LogTemp, Error, TEXT("%s: %s"), *GetOwner()->GetName(), *FString("I didnt find an input component, meng."))
	}
}



void UGrabber::GrabPressed()
{
	FindPhysicsObjectinRange();
	UE_LOG(LogTemp, Warning, TEXT("%s: GRAB PENIS PRESSED!!."), *GetOwner()->GetName())
}

const FHitResult UGrabber::FindPhysicsObjectinRange()
{
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
	FHitResult Hit;
	FCollisionQueryParams MyTraceParams(FName(TEXT("ASS MONKEY PARAMS")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		MyTraceParams);


	if (Hit.GetActor() != nullptr) {
		AActor* HitActor = Hit.GetActor();
		FString ActorName = HitActor->GetName();
		UE_LOG(LogTemp, Warning, TEXT("HIT ACTOR: %s"), *ActorName);
	}

	return FHitResult();
}

void UGrabber::GrabReleased()
{
	UE_LOG(LogTemp, Error, TEXT("%s: GRAB PENIS RELEASED!!."), *GetOwner()->GetName())
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//get ass

			
		
}

