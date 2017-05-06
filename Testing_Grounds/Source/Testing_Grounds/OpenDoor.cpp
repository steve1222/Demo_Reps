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
	
	// ...
	
}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();
	FRotator newRotation = FRotator(0.f, 90.f, 0.0f);
	Owner->SetActorRotation(newRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if ((*TrigPointer).IsOverlappingActor(ActorPointer)) {
		OpenDoor();
	}
	// ...
}

