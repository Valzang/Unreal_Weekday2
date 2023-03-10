#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CStateComponent.h"
#include "CPlayer.generated.h"

UCLASS()
class UNREALPROJ2_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

private :
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm; 
	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera; 
	UPROPERTY(VisibleDefaultsOnly)
		class UCOptionComponent* Option;
	UPROPERTY(VisibleDefaultsOnly)
		class UCStatusComponent* Status;
	UPROPERTY(VisibleDefaultsOnly)
		class UCStateComponent* State;
	UPROPERTY(VisibleDefaultsOnly)
		class UCMontagesComponent* Montages;
	UPROPERTY(VisibleDefaultsOnly)
		class UCActionComponent* Action;

private:
	void OnMoveForward(float InAxis);
	void OnMoveRight(float InAxis);
	void OnHorizontalLook(float InAxis);
	void OnVerticalLook(float InAxis);

	void OnAvoid();
	void OnOneHand();

	void Begin_Roll();
	void Begin_Backstep();

	UFUNCTION()
		void OnStateTypeChanged(EStateType InPrevType, EStateType InNewType);
protected:
	virtual void BeginPlay() override;

public:
	ACPlayer();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void End_Roll();
	void End_Backstep();



};
