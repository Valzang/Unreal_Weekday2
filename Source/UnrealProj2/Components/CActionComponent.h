#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CActionComponent.generated.h"

UENUM(BlueprintType)
enum class EActionType : uint8
{
	Unarmed, OneHand, TwoHand, Max
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActionTypeChanged, EActionType, InPrevType, EActionType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROJ2_API UCActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCActionComponent();

protected:
	virtual void BeginPlay() override;

private:
	EActionType Type;

public:
	UPROPERTY(BlueprintAssignable)
		FActionTypeChanged OnActionTypeChanged;

	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsUnarmedMode() 
			{ return Type == EActionType::Unarmed ; }
	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsOneHandMode() 
			{ return Type == EActionType::OneHand; }
	UFUNCTION(BlueprintPure)
		FORCEINLINE bool IsTwoHandMode()
			{ return Type == EActionType::TwoHand; }

	void SetUnarmedMode();
	void SetOneHandMode();
	void SetTwoHandMode();

private:
	void ChangeType(EActionType InNewType);
	void SetMode(EActionType InType);
	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
		class UCActionData* Datas[(int32)EActionType::Max];
};
