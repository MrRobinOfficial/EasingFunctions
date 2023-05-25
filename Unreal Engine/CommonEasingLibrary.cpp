// Copyright 2023 MrRobin. All Rights Reserved.

#include "Library/CommonEasingLibrary.h"

float UCommonEasingLibrary::GetEaseFromType(EEaseType EaseType, float Start, float End, float Alpha)
{
	switch (EaseType)
	{
		default:
			return 0.0f;

		case EEaseType::Linear:
			return EaseLinear(Start, End, Alpha);

		case EEaseType::Spring:
			return EaseSpring(Start, End, Alpha);

		case EEaseType::EaseInQuad:
			return EaseInQuad(Start, End, Alpha);

		case EEaseType::EaseOutQuad:
			return EaseOutQuad(Start, End, Alpha);

		case EEaseType::EaseInOutQuad:
			return EaseInOutQuad(Start, End, Alpha);

		case EEaseType::EaseInCubic:
			return EaseInCubic(Start, End, Alpha);

		case EEaseType::EaseOutCubic:
			return EaseOutCubic(Start, End, Alpha);

		case EEaseType::EaseInOutCubic:
			return EaseInOutCubic(Start, End, Alpha);

		case EEaseType::EaseInQuart:
			return EaseInQuart(Start, End, Alpha);

		case EEaseType::EaseOutQuart:
			return EaseOutQuart(Start, End, Alpha);

		case EEaseType::EaseInOutQuart:
			return EaseInOutQuart(Start, End, Alpha);

		case EEaseType::EaseInQuint:
			return EaseInQuint(Start, End, Alpha);

		case EEaseType::EaseOutQuint:
			return EaseOutQuint(Start, End, Alpha);

		case EEaseType::EaseInOutQuint:
			return EaseInOutQuint(Start, End, Alpha);

		case EEaseType::EaseInSine:
			return EaseInSine(Start, End, Alpha);

		case EEaseType::EaseOutSine:
			return EaseOutSine(Start, End, Alpha);

		case EEaseType::EaseInOutSine:
			return EaseInOutSine(Start, End, Alpha);

		case EEaseType::EaseInExpo:
			return EaseInExpo(Start, End, Alpha);

		case EEaseType::EaseOutExpo:
			return EaseOutExpo(Start, End, Alpha);

		case EEaseType::EaseInOutExpo:
			return EaseInOutExpo(Start, End, Alpha);

		case EEaseType::EaseInCirc:
			return EaseInCirc(Start, End, Alpha);

		case EEaseType::EaseOutCirc:
			return EaseOutCirc(Start, End, Alpha);

		case EEaseType::EaseInOutCirc:
			return EaseInOutCirc(Start, End, Alpha);

		case EEaseType::EaseInBounce:
			return EaseInBounce(Start, End, Alpha);

		case EEaseType::EaseOutBounce:
			return EaseOutBounce(Start, End, Alpha);

		case EEaseType::EaseInOutBounce:
			return EaseInOutBounce(Start, End, Alpha);

		case EEaseType::EaseInBack:
			return EaseInBack(Start, End, Alpha);

		case EEaseType::EaseOutBack:
			return EaseOutBack(Start, End, Alpha);

		case EEaseType::EaseInOutBack:
			return EaseInOutBack(Start, End, Alpha);

		case EEaseType::EaseInElastic:
			return EaseInElastic(Start, End, Alpha);

		case EEaseType::EaseOutElastic:
			return EaseOutElastic(Start, End, Alpha);

		case EEaseType::EaseInOutElastic:
			return EaseInOutElastic(Start, End, Alpha);
	}
}

float UCommonEasingLibrary::EaseLinear(float Start, float End, float Alpha)
{
	return FMath::Lerp(Start, End, Alpha);
}

float UCommonEasingLibrary::EaseSpring(float Start, float End, float Alpha)
{
	Alpha = FMath::Clamp(Alpha, 0.0f, 1.0f);

	Alpha = (FMath::Sin(Alpha * PI * (0.2f + 2.5f * Alpha * Alpha * Alpha)) * FMath::Pow(1.0f - Alpha, 2.2f) + Alpha) * (1.0f + (1.2f * (1.0f - Alpha)));

	return Start + (End - Start) * Alpha;
}

float UCommonEasingLibrary::EaseInQuad(float Start, float End, float Alpha)
{
	End -= Start;
	return End * Alpha * Alpha + Start;
}

float UCommonEasingLibrary::EaseOutQuad(float Start, float End, float Alpha)
{
	End -= Start;
	return -End * Alpha * (Alpha - 2.0f) + Start;
}

float UCommonEasingLibrary::EaseInOutQuad(float Start, float End, float Alpha)
{
	Alpha /= 0.5f;
	End -= Start;

	if (Alpha < 1.0f)
		return End * 0.5f * Alpha * Alpha + Start;

	Alpha--;

	return -End * 0.5f * (Alpha * (Alpha - 2.0f) - 1.0f) + Start;
}

float UCommonEasingLibrary::EaseInCubic(float Start, float End, float Alpha)
{
	End -= Start;
	return End * Alpha * Alpha * Alpha + Start;
}

float UCommonEasingLibrary::EaseOutCubic(float Start, float End, float Alpha)
{
	Alpha--;
	End -= Start;

	return End * (Alpha * Alpha * Alpha + 1.0f) + Start;
}

float UCommonEasingLibrary::EaseInOutCubic(float Start, float End, float Alpha)
{
	Alpha /= 0.5f;
	End -= Start;

	if (Alpha < 1.0f)
		return End * 0.5f * Alpha * Alpha * Alpha + Start;

	Alpha -= 2.0f;
	return End * 0.5f * (Alpha * Alpha * Alpha + 2.0f) + Start;
}

float UCommonEasingLibrary::EaseInQuart(float Start, float End, float Alpha)
{
	End -= Start;
	return End * Alpha * Alpha * Alpha * Alpha + Start;
}

float UCommonEasingLibrary::EaseOutQuart(float Start, float End, float Alpha)
{
	Alpha--;
	End -= Start;
	return -End * (Alpha * Alpha * Alpha * Alpha - 1.0f) + Start;
}

float UCommonEasingLibrary::EaseInOutQuart(float Start, float End, float Alpha)
{
	Alpha /= .5f;
	End -= Start;
	if (Alpha < 1) return End * 0.5f * Alpha * Alpha * Alpha * Alpha + Start;
	Alpha -= 2;
	return -End * 0.5f * (Alpha * Alpha * Alpha * Alpha - 2) + Start;
}

float UCommonEasingLibrary::EaseInQuint(float Start, float End, float Alpha)
{
	End -= Start;
	return End * Alpha * Alpha * Alpha * Alpha * Alpha + Start;
}

float UCommonEasingLibrary::EaseOutQuint(float Start, float End, float Alpha)
{
	Alpha--;
	End -= Start;
	return End * (Alpha * Alpha * Alpha * Alpha * Alpha + 1) + Start;
}

float UCommonEasingLibrary::EaseInOutQuint(float Start, float End, float Alpha)
{
	Alpha /= .5f;
	End -= Start;
	if (Alpha < 1) return End * 0.5f * Alpha * Alpha * Alpha * Alpha * Alpha + Start;
	Alpha -= 2;
	return End * 0.5f * (Alpha * Alpha * Alpha * Alpha * Alpha + 2) + Start;
}

float UCommonEasingLibrary::EaseInSine(float Start, float End, float Alpha)
{
	End -= Start;
	return -End * FMath::Cos(Alpha * (PI * 0.5f)) + End + Start;
}

float UCommonEasingLibrary::EaseOutSine(float Start, float End, float Alpha)
{
	End -= Start;
	return End * FMath::Sin(Alpha * (PI * 0.5f)) + Start;
}

float UCommonEasingLibrary::EaseInOutSine(float Start, float End, float Alpha)
{
	End -= Start;
	return -End * 0.5f * (FMath::Cos(PI * Alpha) - 1) + Start;
}

float UCommonEasingLibrary::EaseInExpo(float Start, float End, float Alpha)
{
	End -= Start;
	return End * FMath::Pow(2, 10 * (Alpha - 1)) + Start;
}

float UCommonEasingLibrary::EaseOutExpo(float Start, float End, float Alpha)
{
	End -= Start;
	return End * (-FMath::Pow(2, -10 * Alpha) + 1) + Start;
}

float UCommonEasingLibrary::EaseInOutExpo(float Start, float End, float Alpha)
{
	Alpha /= .5f;
	End -= Start;

	if (Alpha < 1)
		return End * 0.5f * FMath::Pow(2, 10 * (Alpha - 1)) + Start;

	Alpha--;

	return End * 0.5f * (-FMath::Pow(2, -10 * Alpha) + 2) + Start;
}

float UCommonEasingLibrary::EaseInCirc(float Start, float End, float Alpha)
{
	End -= Start;
	return -End * (FMath::Sqrt(1 - Alpha * Alpha) - 1) + Start;
}

float UCommonEasingLibrary::EaseOutCirc(float Start, float End, float Alpha)
{
	Alpha--;
	End -= Start;
	return End * FMath::Sqrt(1 - Alpha * Alpha) + Start;
}

float UCommonEasingLibrary::EaseInOutCirc(float Start, float End, float Alpha)
{
	Alpha /= .5f;
	End -= Start;
	if (Alpha < 1) return -End * 0.5f * (FMath::Sqrt(1 - Alpha * Alpha) - 1) + Start;
	Alpha -= 2;
	return End * 0.5f * (FMath::Sqrt(1 - Alpha * Alpha) + 1) + Start;
}

float UCommonEasingLibrary::EaseInBounce(float Start, float End, float Alpha)
{
	End -= Start;
	float d = 1.0f;
	return End - EaseOutBounce(0, End, d - Alpha) + Start;
}

float UCommonEasingLibrary::EaseOutBounce(float Start, float End, float Alpha)
{
	Alpha /= 1.0f;
	End -= Start;
	if (Alpha < (1 / 2.75f))
	{
		return End * (7.5625f * Alpha * Alpha) + Start;
	}
	else if (Alpha < (2 / 2.75f))
	{
		Alpha -= (1.5f / 2.75f);
		return End * (7.5625f * (Alpha)*Alpha + .75f) + Start;
	}
	else if (Alpha < (2.5 / 2.75))
	{
		Alpha -= (2.25f / 2.75f);
		return End * (7.5625f * (Alpha)*Alpha + .9375f) + Start;
	}
	else
	{
		Alpha -= (2.625f / 2.75f);
		return End * (7.5625f * (Alpha)*Alpha + .984375f) + Start;
	}
}

float UCommonEasingLibrary::EaseInOutBounce(float Start, float End, float Alpha)
{
	End -= Start;
	float d = 1.0f;
	if (Alpha < d * 0.5f) return EaseInBounce(0, End, Alpha * 2) * 0.5f + Start;
	else return EaseOutBounce(0, End, Alpha * 2 - d) * 0.5f + End * 0.5f + Start;
}

float UCommonEasingLibrary::EaseInBack(float Start, float End, float Alpha)
{
	End -= Start;
	Alpha /= 1;
	float s = 1.70158f;
	return End * (Alpha)*Alpha * ((s + 1) * Alpha - s) + Start;
}

float UCommonEasingLibrary::EaseOutBack(float Start, float End, float Alpha)
{
	float s = 1.70158f;
	End -= Start;
	Alpha = (Alpha)-1;
	return End * ((Alpha)*Alpha * ((s + 1) * Alpha + s) + 1) + Start;
}

float UCommonEasingLibrary::EaseInOutBack(float Start, float End, float Alpha)
{
	float s = 1.70158f;
	End -= Start;
	Alpha /= .5f;
	if ((Alpha) < 1)
	{
		s *= (1.525f);
		return End * 0.5f * (Alpha * Alpha * (((s)+1) * Alpha - s)) + Start;
	}
	Alpha -= 2;
	s *= (1.525f);
	return End * 0.5f * ((Alpha)*Alpha * (((s)+1) * Alpha + s) + 2) + Start;
}

float UCommonEasingLibrary::EaseInElastic(float Start, float End, float Alpha)
{
	End -= Start;

	float d = 1.0f;
	float p = d * .3f;
	float s;
	float a = 0;

	if (Alpha == 0)
		return Start;

	if ((Alpha /= d) == 1)
		return Start + End;

	if (a == 0.0f || a < FMath::Abs(End))
	{
		a = End;
		s = p / 4;
	}
	else
		s = p / (2 * PI) * FMath::Asin(End / a);

	return -(a * FMath::Pow(2, 10 * (Alpha -= 1)) * FMath::Sin((Alpha * d - s) * (2 * PI) / p)) + Start;
}

float UCommonEasingLibrary::EaseOutElastic(float Start, float End, float Alpha)
{
	End -= Start;

	float d = 1.0f;
	float p = d * .3f;
	float s;
	float a = 0;

	if (Alpha == 0) return Start;

	if ((Alpha /= d) == 1) return Start + End;

	if (a == 0.0f || a < FMath::Abs(End))
	{
		a = End;
		s = p * 0.25f;
	}
	else
	{
		s = p / (2 * PI) * FMath::Asin(End / a);
	}

	return (a * FMath::Pow(2, -10 * Alpha) * FMath::Sin((Alpha * d - s) * (2 * PI) / p) + End + Start);
}

float UCommonEasingLibrary::EaseInOutElastic(float Start, float End, float Alpha)
{
	End -= Start;

	float d = 1.0f;
	float p = d * .3f;
	float s;
	float a = 0;

	if (Alpha == 0) return Start;

	if ((Alpha /= d * 0.5f) == 2) return Start + End;

	if (a == 0.0f || a < FMath::Abs(End))
	{
		a = End;
		s = p / 4;
	}
	else
	{
		s = p / (2 * PI) * FMath::Asin(End / a);
	}

	if (Alpha < 1) return -0.5f * (a * FMath::Pow(2, 10 * (Alpha -= 1)) * FMath::Sin((Alpha * d - s) * (2 * PI) / p)) + Start;
	return a * FMath::Pow(2, -10 * (Alpha -= 1)) * FMath::Sin((Alpha * d - s) * (2 * PI) / p) * 0.5f + End + Start;
}