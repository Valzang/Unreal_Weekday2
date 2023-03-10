#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CActionData.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		class UAnimMontage* AnimMontage;
	UPROPERTY(EditAnywhere)
		float PlayRatio = 1.0f;
	UPROPERTY(EditAnywhere)
		FName StartSection;
	UPROPERTY(EditAnywhere)
		bool bCanMove = true;
};

UCLASS()
class UNREALPROJ2_API UCActionData : public UDataAsset
{
	GENERATED_BODY()

private:
	class ACEquipment* Equipment;

public:
	void BeginPlay(class ACharacter* InOwnerCharacter);

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		TSubclassOf<class ACEquipment> EquipmentClass;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FEquipmentData	EquimentData;
	FORCEINLINE class ACEquipment* GetEquipment() { return Equipment; }
};
