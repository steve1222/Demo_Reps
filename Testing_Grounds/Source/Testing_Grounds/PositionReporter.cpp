// Fill out your copyright notice in the Description page of Project Settings.

#include "Testing_Grounds.h"
#include "PositionReporter.h"


// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("PENiS WHOERS"));
	// ...
}


// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();
	
	FString dickcake = (*GetOwner()).GetName();
	 
	 FString asshat= GetOwner()->GetActorLocation().ToString();
	 GetWorld();
	UE_LOG(LogTemp, Error, TEXT("LOCATION NIGGER: %s"),*asshat);
	// ...
	
}


// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

