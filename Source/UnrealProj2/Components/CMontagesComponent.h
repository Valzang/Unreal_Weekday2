#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/CStateComponent.h"
#include "Engine/DataTable.h"
#include "CMontagesComponent.generated.h"

USTRUCT(BlueprintType)
struct FMontageData : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		EStateType Type;
	UPROPERTY(EditAnywhere)
		class UAnimMontage* AnimMontage;
	UPROPERTY(EditAnywhere)
		float PlayRatio = 1.0f;
	UPROPERTY(EditAnywhere)
		FName StartSection;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROJ2_API UCMontagesComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "DataTable")
		UDataTable* DataTable;

	FMontageData* Datas[(int32)EStateType::Max];

public:	
	UCMontagesComponent() {};
	void PlayRoll();
	void PlayBackstep();

protected:
	virtual void BeginPlay() override;

private:
	void PlayAnimMontage(EStateType InState);

		
};
