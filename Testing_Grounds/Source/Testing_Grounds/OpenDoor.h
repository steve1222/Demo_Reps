// copyrite an4l beads netw0rk 2017 we plug em we love em

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


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

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenDelta = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* TriggerReference;

	AActor* PlayerPawnReference;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;

	float LastDoorOpenTime;
	AActor* Owner = GetOwner();
	FRotator openRotation;
	FRotator closeRotation;
//	UPROPERTY(EditAnywhere)
	//	APawn* PawnPointer;
	
};
