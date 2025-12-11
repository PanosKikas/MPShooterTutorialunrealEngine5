// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class UBoxComponent;
class UParticleSystem;

UCLASS()
class BLASTER_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	AProjectile();
	virtual void Destroyed() override;

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> CollisionBox;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UParticleSystem> Tracer;
	
	UPROPERTY()	
	TObjectPtr<UParticleSystemComponent> TracerComponent;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UParticleSystem> ImpactParticles;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundCue> ImpactSound;
	
public:
	virtual void Tick(float DeltaTime) override;
};
