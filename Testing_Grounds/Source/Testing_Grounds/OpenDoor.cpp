// copyrite an4l beads netw0rk 2017 we plug em we love em

#include "Testing_Grounds.h"
#include "OpenDoor.h"

#define OUT
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
	//Owner->SetActorRotation(openRotation);
	OnOpenRequest.Broadcast();
}
void UOpenDoor::CloseDoor()
{
	OnCloseRequest.Broadcast();
	//Owner->SetActorRotation(closeRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// if we want to set a trigger that opens door instantly on player overlap
	if (InstantTriggerReference){
		InstantTriggerDoor();
	}
	// if we are using a trigger that waits for total mass to validate, before doorOpen
	if (TotalMassTriggerReference) {
		if (GetTotalMassOfActorsOnPlate() > RequiredOpenMass) {
			OpenDoor();
			LastDoorOpenTime = GetWorld()->GetTimeSeconds();
		}
		if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
			CloseDoor();
		}
	}
	// ...
}

void UOpenDoor::InstantTriggerDoor() {
	if (InstantTriggerReference->IsOverlappingActor(PlayerPawnReference)) {
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	if (LastDoorOpenTime) {
		if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
			CloseDoor();
		}
	}
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() {
	float Total_Mass = 0.f;
	TArray<AActor*> OverlappingActorArray;
	TotalMassTriggerReference->GetOverlappingActors(OUT OverlappingActorArray);
	for (const auto* element : OverlappingActorArray) {
		//UE_LOG(LogTemp, Warning, TEXT("Overlapping Actor entity: %s"), *(element->GetName()))
			Total_Mass+= (element->FindComponentByClass<UPrimitiveComponent>()->GetMass());
			
		/* //doesn't work \/
			UStaticMeshComponent* comp = Cast<UStaticMeshComponent>(index);
			if (comp)
			{
				Total_Mass += comp->GetMass();
				UE_LOG(LogTemp, Warning, TEXT("Total Mass: %f"), Total_Mass)
			}
			             /\ */
	}
	if (Total_Mass) { UE_LOG(LogTemp, Warning, TEXT("Total Mass: %f"), Total_Mass) }
	return Total_Mass;
}

