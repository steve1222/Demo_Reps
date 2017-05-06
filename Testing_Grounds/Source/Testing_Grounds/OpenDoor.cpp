// copyrite an4l beads netw0rk 2017 we plug em we love em

#include "Testing_Grounds.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerPawnReference = GetWorld()->GetFirstPlayerController()->GetPawn();
	openRotation = Owner->GetActorRotation();
	closeRotation = Owner->GetActorRotation();
	openRotation.Yaw += OpenDelta;
//	closeRotation.Yaw -= 90.f;
	
}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(openRotation);
}
void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(closeRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (TriggerReference){
		if (TriggerReference->IsOverlappingActor(PlayerPawnReference)) {
			OpenDoor();
			LastDoorOpenTime = GetWorld()->GetTimeSeconds();
		}
		if (LastDoorOpenTime) {
			if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
				CloseDoor();
			}
		}
	}
	// ...
}

