// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Casing.generated.h"

class USoundCue;

UCLASS()
class BLASTER_API ACasing : public AActor
{
	GENERATED_BODY()

public:
	ACasing();

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> CasingMesh;
	
	UPROPERTY(EditAnywhere)
	float ShellEjectionImpulse;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundCue> ShellSound;
	
	FTimerHandle TimerHandle;
	
	void DestroyCasing();
	
	UPROPERTY(EditAnywhere)
	float DestroyTimer = 5.f;
	
protected:
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	virtual void BeginPlay() override;
};
