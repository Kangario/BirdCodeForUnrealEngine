// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/MyPawn.h"

AMyPawn::AMyPawn()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);

	BirdMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BirdMesh"));
	BirdMesh->SetupAttachment(GetRootComponent());
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;



}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}
void AMyPawn::Turn(float Value)
{
	AddControllerYawInput(Value);
}
void AMyPawn::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyPawn::MoveForward(float Value)
{	
if ((Controller != nullptr)&&(Value!=0.f))
{
FVector Forward =  GetActorForwardVector();
AddMovementInput(Forward, Value);
}
}
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"),this,&AMyPawn::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"),this,&AMyPawn::LookUp);
}

