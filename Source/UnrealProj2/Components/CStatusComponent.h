// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROJ2_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "Speed")
		float WalkSpeed = 200.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Speed")
		float RunSpeed = 400.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Speed")
		float SprintSpeed = 600.0f;

	bool bCanMove = true;

public:
	UCStatusComponent();

	FORCEINLINE float GetWalkSpeed() { return WalkSpeed; }
	FORCEINLINE float GetRunSpeed() { return RunSpeed; }
	FORCEINLINE float GetSprintSpeed() { return SprintSpeed; }
	FORCEINLINE bool CanMove() { return bCanMove; }

	void SetMove();
	void SetStop();


protected:
	virtual void BeginPlay() override;

		
};
