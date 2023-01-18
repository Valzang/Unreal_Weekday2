#include "CAnimNotifiy_EndBackstep.h"
#include "Global.h"
#include "Characters/CPlayer.h"

FString UCAnimNotifiy_EndBackstep::GetNotifyName_Implementation() const
{
	return "Backstep";
}

void UCAnimNotifiy_EndBackstep::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	ACPlayer* player = Cast<ACPlayer>(MeshComp->GetOwner());
	CheckNull(player);

	player->End_Backstep();

}
