// Copyright 2023 MrRobin. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CommonEasingLibrary.generated.h"

UENUM(BlueprintType)
enum class EEaseType : uint8
{
    Linear = 0,
    Spring,
    EaseInQuad,
    EaseOutQuad,
    EaseInOutQuad,
    EaseInCubic,
    EaseOutCubic,
    EaseInOutCubic,
    EaseInQuart,
    EaseOutQuart,
    EaseInOutQuart,
    EaseInQuint,
    EaseOutQuint,
    EaseInOutQuint,
    EaseInSine,
    EaseOutSine,
    EaseInOutSine,
    EaseInExpo,
    EaseOutExpo,
    EaseInOutExpo,
    EaseInCirc,
    EaseOutCirc,
    EaseInOutCirc,
    EaseInBounce,
    EaseOutBounce,
    EaseInOutBounce,
    EaseInBack,
    EaseOutBack,
    EaseInOutBack,
    EaseInElastic,
    EaseOutElastic,
    EaseInOutElastic
};

UCLASS()
class COMMONLIBRARY_API UCommonEasingLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float GetEaseFromType(EEaseType EaseType, float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseLinear(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseSpring(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInQuad(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutQuad(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutQuad(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInCubic(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutCubic(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutCubic(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInQuart(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutQuart(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutQuart(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInQuint(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutQuint(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutQuint(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInSine(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutSine(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutSine(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInExpo(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutExpo(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutExpo(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInCirc(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutCirc(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutCirc(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInBounce(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutBounce(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutBounce(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInBack(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutBack(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutBack(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInElastic(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseOutElastic(float Start, float End, float Alpha);

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Easing")
    static float EaseInOutElastic(float Start, float End, float Alpha);
};
