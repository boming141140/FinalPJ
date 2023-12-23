#include "CoreMinimal.h"
#include "MyItem.h"
#include "material_limb.generated.h"

UENUM(BlueprintType)
enum class MaterialType : uint8
{
    wood UMETA(DisplayName = "wood"),
    steel UMETA(DisplayName = "steel"),
    rubber UMETA(DisplayName = "rubber"),
    rock UMETA(DisplayName = "rock"),
    copper UMETA(DisplayName = "copper"),
    
};

enum class BodyParts : uint8
{
    head UMETA(DisplayName = "head"),
    LeftArm UMETA(DisplayName = "LeftArm"),
    RightArm UMETA(DisplayName = "RightArm"),
    LeftLeg UMETA(DisplayName = "LeftLeg"),
    RightLeg UMETA(DisplayName = "RightLeg"),
    Nothing UMETA(DisplayName = "Nothing")
};


enum class Weight : uint8
{
    light UMETA(DisplayName = "light"),
    medium UMETA(DisplayName = "medium"),
    heavy UMETA(DisplayName = "heavy"),
   
};

enum class Bouncy : uint8
{
    NotBouncy UMETA(DisplayName = "NotBouncy"),
    LittleBouncy UMETA(DisplayName = "LittleBouncy"),
    Bouncy UMETA(DisplayName = "Bouncy"),

};

enum class Length : uint8
{
    ShortLength UMETA(DisplayName = "ShortLength"),
    MediumLength UMETA(DisplayName = "MediumLength"),
    FullLength UMETA(DisplayName = "FullLength"),

};

UCLASS()
class FINALPJ_API Umaterial_limb : public UMyItem
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    Umaterial_limb();
    Umaterial_limb(BodyParts BodyPartsName);
    MaterialType type;
    MaterialType GetType() const { return type; }
    Weight GetMass() const { return mass; }
    Bouncy GetBouncy() const { return bouncy; }
    Length GetLength() const { return length; }
    bool IsFireResistant() const { return fireResist; }
    int32 GetHealth() const { return health; }
    BodyParts GetBodyPart() const { return BodyPartsName; }
public:

    

    virtual void Use() override;

    void setType(MaterialType NewType);
    void setBodyPart(BodyParts NewBodyPart);
private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
    Weight mass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
    Bouncy bouncy;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
    Length length;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom")
    bool fireResist;
    int32 health;
    BodyParts BodyPartsName;
};
