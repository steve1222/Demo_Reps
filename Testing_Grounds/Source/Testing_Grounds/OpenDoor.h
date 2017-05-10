// copyrite an4l beads netw0rk 2017 we plug em we love em

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTING_GROUNDS_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();
	// legacy version for opening door on overlap
	void InstantTriggerDoor();
	//returns total trigger mass in Kg
	float GetTotalMassOfActorsOnPlate();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpenRequest;
	UPROPERTY(BlueprintAssignable)
		FDoorEvent OnCloseRequest;
private:
	//total angle to add to mesh's rotator yaw on open animation
	UPROPERTY(EditAnywhere)
	float OpenDelta = 90.f;
	// optional trigger that opens door instantly on player overlap
	UPROPERTY(EditAnywhere)
	ATriggerVolume* InstantTriggerReference;
	// optional trigger that opens door when total weight equals desired weight in kg
	UPROPERTY(EditAnywhere)
	ATriggerVolume* TotalMassTriggerReference;

	AActor* PlayerPawnReference;

	//the delay in seconds before closing door after stepping off volume
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;
	// the total mass needed to open door for weighted trigger reference
	UPROPERTY(EditAnywhere)
	float RequiredOpenMass = 100.f;

	float LastDoorOpenTime;
	AActor* Owner = GetOwner();
	FRotator openRotation;
	FRotator closeRotation;
//	UPROPERTY(EditAnywhere)
	//	APawn* PawnPointer;
	
};
