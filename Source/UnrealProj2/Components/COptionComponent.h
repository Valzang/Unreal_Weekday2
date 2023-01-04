#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "COptionComponent.generated.h"


UCLASS( ClassGroup=(GameProject), meta=(BlueprintSpawnableComponent) )
class UNREALPROJ2_API UCOptionComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
		float HorizontalLookRate = 45;
	UPROPERTY(EditDefaultsOnly)
		float VerticalLookRate = 45;

public:
	UCOptionComponent();

	FORCEINLINE float GetHorizontalLookRate() { return HorizontalLookRate; }
	FORCEINLINE float GetVerticalLookRate() { return VerticalLookRate; }

protected:
	virtual void BeginPlay() override;

		
};
