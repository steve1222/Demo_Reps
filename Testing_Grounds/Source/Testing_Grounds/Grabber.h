// copyrite an4l beads netw0rk 2017 we plug em we love em

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Penis), meta=(BlueprintSpawnableComponent) )
class TESTING_GROUNDS_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	UPROPERTY(EditAnywhere)
		float Reach = 1000.0f;
	// ray-cast and grab whats in reach
	void ActionGrab();
	void ActionRelease();

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	// get the physics handle we added to the pawn
	void GetPhysicsHandle();
	//setup (assumed) attached input component
	void BindActionToGrab();
	//return hit result after finding a physics component
	const FHitResult FindPhysicsBodyinRange();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPhysicsHandleComponent* physxHandleComp = nullptr;
	UInputComponent* ownerInputComponent;
	AActor* HitActor = nullptr;
	FString ActorName;
	FHitResult HitResult;
	float Magnitude;
	FVector PlayerViewPointLocation;
	
};


