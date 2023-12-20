#include "CoreMinimal.h"
#include "material_limb.h"
#include "GameFramework/Actor.h"
#include "mannequin.generated.h"

UCLASS()
class FINALPJ_API Amannequin : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	Amannequin();
	Amannequin(Umaterial_limb* LeftHand, Umaterial_limb* RightHand, Umaterial_limb* LeftLeg, Umaterial_limb* RightLeg);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Limbs", meta = (AllowPrivateAccess = "true"))
	Umaterial_limb* LeftArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Limbs", meta = (AllowPrivateAccess = "true"))
	Umaterial_limb* RightArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Limbs", meta = (AllowPrivateAccess = "true"))
	Umaterial_limb* LeftLeg;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Limbs", meta = (AllowPrivateAccess = "true"))
	Umaterial_limb* RightLeg;

	void StatsCheck();
	void equip(Umaterial_limb* limbs);
	void drop(Umaterial_limb* limbs);
};
