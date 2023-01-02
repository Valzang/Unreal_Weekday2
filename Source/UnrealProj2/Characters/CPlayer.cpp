#include "CPlayer.h"
#include "Global.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"


ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	CHelpers::CreateComponent<USpringArmComponent>(this, &SpringArm,
		"SpringArm", GetMesh()); 
	CHelpers::CreateComponent<UCameraComponent>(this, &Camera,
		"Camera", SpringArm); 

	bUseControllerRotationYaw = false; 

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90)); 
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0)); 

	USkeletalMesh* mesh; 
	CHelpers::GetAsset<USkeletalMesh>(&mesh, 
		"SkeletalMesh'/Game/Character/Mesh/SK_Mannequin.SK_Mannequin'"); 
	GetMesh()->SetSkeletalMesh(mesh); 

	SpringArm->SetRelativeLocation(FVector(0, 0, 140)); 
	SpringArm->SetRelativeRotation(FRotator(0, 90, 0)); 
	SpringArm->TargetArmLength = 200.0f; 
	SpringArm->bDoCollisionTest = false; 
	SpringArm->bUsePawnControlRotation = true; 
	SpringArm->bEnableCameraLag = true; 

	GetCharacterMovement()->RotationRate = FRotator(0, 720, 0); 
	GetCharacterMovement()->bOrientRotationToMovement = true; 
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}


void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

