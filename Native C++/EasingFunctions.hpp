/*
 * Created by C.J. Kimberlin
 * 
 * The MIT License (MIT)
 * 
 * Copyright (c) 2019
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * 
 * TERMS OF USE - EASING EQUATIONS
 * Open source under the BSD License.
 * Copyright (c)2001 Robert Penner
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of the author nor the names of contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * ============= Description =============
 *
 * Below is an example of how to use the easing functions in the file. There is a getting function that will return the function
 * from an enum. This is useful since the enum can be exposed in the editor and then the function queried during start().
 * 
 * EasingFunction.Ease ease = EasingFunction.Ease.EaseInOutQuad;
 * EasingFunction.EasingFunc func = GetEasingFunction(ease;
 * 
 * float alpha = func(0, 10, 0.67f);
 * 
 * EasingFunction.EaseingFunc derivativeFunc = GetEasingFunctionDerivative(ease);
 * 
 * float derivativeValue = derivativeFunc(0, 10, 0.67f);
 */

#include <cmath>

class EasingFunctions
{
    #define NATURAL_LOG_OF_2 0.693147181f
    #define PI 3.14159274101257324219f

public:
    enum EEaseType : unsigned int
    {
        EASE_LINEAR = 0,
        EASE_SPRING,
        EASE_IN_QUAD,
        EASE_OUT_QUAD,
        EASE_IN_OUT_QUAD,
        EASE_IN_CUBIC,
        EASE_OUT_CUBIC,
        EASE_IN_OUT_CUBIC,
        EASE_IN_QUART,
        EASE_OUT_QUART,
        EASE_IN_OUT_QUART,
        EASE_IN_QUINT,
        EASE_OUT_QUINT,
        EASE_IN_OUT_QUINT,
        EASE_IN_SINE,
        EASE_OUT_SINE,
        EASE_IN_OUT_SINE,
        EASE_IN_EXPO,
        EASE_OUT_EXPO,
        EASE_IN_OUT_EXPO,
        EASE_IN_CIRC,
        EASE_OUT_CIRC,
        EASE_IN_OUT_CIRC,
        EASE_IN_BOUNCE,
        EASE_OUT_BOUNCE,
        EASE_IN_OUT_BOUNCE,
        EASE_IN_BACK,
        EASE_OUT_BACK,
        EASE_IN_OUT_BACK,
        EASE_IN_ELASTIC,
        EASE_OUT_ELASTIC,
        EASE_IN_OUT_ELASTIC
    };

private:
    template<typename T>
    static T Lerp(T a, T b, T t)
    {
        return a * (T(1.0f) -t) + (b * t);
    }

    template<typename T>
    static T Pow(T base, T exponent)
    {
        T result = T(1.0f);

        for (T i = 0; i < exponent; ++i) {
            result *= base;
        }

        return result;
    }

    template<typename T>
    static T Sin(T x)
    {
        T result = x;
        T term = x;
        T x_squared = -x * x;
        T factorial = 1;
        T denominator = 1;

        for (int i = 1; i < 10; i++) {
            factorial *= i;
            denominator *= 2 * i * (2 * i + 1);
            term *= x_squared / denominator;
            
            if (i % 2 == 1) {
                result -= term;
            } else {
                result += term;
            }
        }

        return result;
    }

    template<typename T>
    static T Clamp(T alpha, T min, T max)
    {
        return alpha < min ? min : (alpha > max ? max : alpha);
    }

public:
    template<typename T>
    static T GetEaseFromType(EEaseType easeType, T start, T end, T alpha)
    {
        switch (easeType)
        {
            default:
                return T(0.0f);

            case EEaseType::EASE_LINEAR:
                return EaseLinear(start, end, alpha);

            case EEaseType::EASE_SPRING:
                return EaseSpring(start, end, alpha);

            case EEaseType::EASE_IN_QUAD:
                return EaseInQuad(start, end, alpha);

            case EEaseType::EASE_OUT_QUAD:
                return EaseOutQuad(start, end, alpha);

            case EEaseType::EASE_IN_OUT_QUAD:
                return EaseInOutQuad(start, end, alpha);

            case EEaseType::EASE_IN_CUBIC:
                return EaseInCubic(start, end, alpha);

            case EEaseType::EASE_OUT_CUBIC:
                return EaseOutCubic(start, end, alpha);

            case EEaseType::EASE_IN_OUT_CUBIC:
                return EaseInOutCubic(start, end, alpha);

            case EEaseType::EASE_IN_QUART:
                return EaseInQuart(start, end, alpha);

            case EEaseType::EASE_OUT_QUART:
                return EaseOutQuart(start, end, alpha);

            case EEaseType::EASE_IN_OUT_QUART:
                return EaseInOutQuart(start, end, alpha);

            case EEaseType::EASE_IN_QUINT:
                return EaseInQuint(start, end, alpha);

            case EEaseType::EASE_OUT_QUINT:
                return EaseOutQuint(start, end, alpha);

            case EEaseType::EASE_IN_OUT_QUINT:
                return EaseInOutQuint(start, end, alpha);

            case EEaseType::EASE_IN_SINE:
                return EaseInSine(start, end, alpha);

            case EEaseType::EASE_OUT_SINE:
                return EaseOutSine(start, end, alpha);

            case EEaseType::EASE_IN_OUT_SINE:
                return EaseInOutSine(start, end, alpha);

            case EEaseType::EASE_IN_EXPO:
                return EaseInExpo(start, end, alpha);

            case EEaseType::EASE_OUT_EXPO:
                return EaseOutExpo(start, end, alpha);

            case EEaseType::EASE_IN_OUT_EXPO:
                return EaseInOutExpo(start, end, alpha);

            case EEaseType::EASE_IN_CIRC:
                return EaseInCirc(start, end, alpha);

            case EEaseType::EASE_OUT_CIRC:
                return EaseOutCirc(start, end, alpha);

            case EEaseType::EASE_IN_OUT_CIRC:
                return EaseInOutCirc(start, end, alpha);

            case EEaseType::EASE_IN_BOUNCE:
                return EaseInBounce(start, end, alpha);

            case EEaseType::EASE_OUT_BOUNCE:
                return EaseOutBounce(start, end, alpha);

            case EEaseType::EASE_IN_OUT_BOUNCE:
                return EaseInOutBounce(start, end, alpha);

            case EEaseType::EASE_IN_BACK:
                return EaseInBack(start, end, alpha);

            case EEaseType::EASE_OUT_BACK:
                return EaseOutBack(start, end, alpha);

            case EEaseType::EASE_IN_OUT_BACK:
                return EaseInOutBack(start, end, alpha);

            case EEaseType::EASE_IN_ELASTIC:
                return EaseInElastic(start, end, alpha);

            case EEaseType::EASE_OUT_ELASTIC:
                return EaseOutElastic(start, end, alpha);

            case EEaseType::EASE_IN_OUT_ELASTIC:
                return EaseInOutElastic(start, end, alpha);
        }
    }

    /// Easing functions ///

    template<typename T>
    static T EaseLinear(T start, T end, T alpha)
    {
        return Lerp(start, end, alpha);
    }

    template<typename T>
    static T EaseSpring(T start, T end, T alpha)
    {
        alpha = Clamp(alpha, T(0.0f), T(1.0f));
        alpha = (Sin(alpha * PI * (T(0.2f) + T(2.5f) * alpha * alpha * alpha)) * Pow(T(1.0f) - alpha, T(2.2f)) + alpha) * (T(1.0f) + (T(1.2f) * (1.0f - alpha)));

        return start + (end - start) * alpha;
    }

    template<typename T>
    static T EaseInQuad(T start, T end, T alpha)
    {
        end -= start;
        return end * alpha * alpha + start;
    }

    template<typename T>
    static T EaseOutQuad(T start, T end, T alpha)
    {
        end -= start;
        return -end * alpha * (alpha - T(2.0f)) + start;
    }

    template<typename T>
    static T EaseInOutQuad(T start, T end, T alpha)
    {
        alpha /= T(0.5f);
        end -= start;
        if (alpha < T(1.0f)) return end * T(0.5f) * alpha * alpha + start;
        alpha--;
        return -end * T(0.5f) * (alpha * (alpha - T(2.0f)) - T(1.0f)) + start;
    }

    template<typename T>
    static float EaseInCubic(T start, T end, T alpha)
    {
        end -= start;
        return end * alpha * alpha * alpha + start;
    }

    template<typename T>
    static float EaseOutCubic(T start, T end, T alpha)
    {
        alpha--;
        end -= start;
        return end * (alpha * alpha * alpha + T(1.0f)) + start;
    }

    template<typename T>
    static float EaseInOutCubic(T start, T end, T alpha)
    {
        alpha /= T(0.5f);
        end -= start;
        if (alpha < T(1.0f)) return end * T(0.5f) * alpha * alpha * alpha + start;
        alpha -= T(2.0f);
        return end * T(0.5f) * (alpha * alpha * alpha + T(2.0f)) + start;
    }

    template<typename T>
    static float EaseInQuart(T start, T end, T alpha)
    {
        end -= start;
        return end * alpha * alpha * alpha * alpha + start;
    }

    template<typename T>
    static float EaseOutQuart(T start, T end, T alpha)
    {
        alpha--;
        end -= start;
        return -end * (alpha * alpha * alpha * alpha - T(1.0f)) + start;
    }

    static float EaseInOutQuart(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;
        if (alpha < 1) return end * 0.5f * alpha * alpha * alpha * alpha + start;
        alpha -= 2;
        return -end * 0.5f * (alpha * alpha * alpha * alpha - 2) + start;
    }

    static float EaseInQuint(float start, float end, float alpha)
    {
        end -= start;
        return end * alpha * alpha * alpha * alpha * alpha + start;
    }

    static float EaseOutQuint(float start, float end, float alpha)
    {
        alpha--;
        end -= start;
        return end * (alpha * alpha * alpha * alpha * alpha + 1) + start;
    }

    static float EaseInOutQuint(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;
        if (alpha < 1) return end * 0.5f * alpha * alpha * alpha * alpha * alpha + start;
        alpha -= 2;
        return end * 0.5f * (alpha * alpha * alpha * alpha * alpha + 2) + start;
    }

    static float EaseInSine(float start, float end, float alpha)
    {
        end -= start;
        return -end * std::cos(alpha * (PI * 0.5f)) + end + start;
    }

    static float EaseOutSine(float start, float end, float alpha)
    {
        end -= start;
        return end * std::sin(alpha * (PI * 0.5f)) + start;
    }

    static float EaseInOutSine(float start, float end, float alpha)
    {
        end -= start;
        return -end * 0.5f * (std::cos(PI * alpha) - 1) + start;
    }

    static float EaseInExpo(float start, float end, float alpha)
    {
        end -= start;
        return end * std::pow(2, 10 * (alpha - 1)) + start;
    }

    static float EaseOutExpo(float start, float end, float alpha)
    {
        end -= start;
        return end * (-std::pow(2, -10 * alpha) + 1) + start;
    }

    static float EaseInOutExpo(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;

        if (alpha < 1)
            return end * 0.5f * std::pow(2, 10 * (alpha - 1)) + start;

        alpha--;

        return end * 0.5f * (-std::pow(2, -10 * alpha) + 2) + start;
    }

    static float EaseInCirc(float start, float end, float alpha)
    {
        end -= start;
        return -end * (std::sqrt(1 - alpha * alpha) - 1) + start;
    }

    static float EaseOutCirc(float start, float end, float alpha)
    {
        alpha--;
        end -= start;
        return end * std::sqrt(1 - alpha * alpha) + start;
    }

    static float EaseInOutCirc(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;
        if (alpha < 1) return -end * 0.5f * (std::sqrt(1 - alpha * alpha) - 1) + start;
        alpha -= 2;
        return end * 0.5f * (std::sqrt(1 - alpha * alpha) + 1) + start;
    }

    static float EaseOutBounce(float start, float end, float alpha)
    {
        alpha /= 1.0f;
        end -= start;
        if (alpha < (1 / 2.75f))
        {
            return end * (7.5625f * alpha * alpha) + start;
        }
        else if (alpha < (2 / 2.75f))
        {
            alpha -= (1.5f / 2.75f);
            return end * (7.5625f * (alpha) * alpha + 0.75f) + start;
        }
        else if (alpha < (2.5 / 2.75))
        {
            alpha -= (2.25f / 2.75f);
            return end * (7.5625f * (alpha) * alpha + .9375f) + start;
        }
        else
        {
            alpha -= (2.625f / 2.75f);
            return end * (7.5625f * (alpha) * alpha + .984375f) + start;
        }
    }

    static float EaseInBounce(float start, float end, float alpha)
    {
        end -= start;
        float d = 1.0f;
        return end - EaseOutBounce(0, end, d - alpha) + start;
    }

    static float EaseInOutBounce(float start, float end, float alpha)
    {
        end -= start;
        float d = 1.0f;
        if (alpha < d * 0.5f) return EaseInBounce(0, end, alpha * 2) * 0.5f + start;
        else return EaseOutBounce(0, end, alpha * 2 - d) * 0.5f + end * 0.5f + start;
    }

    static float EaseInBack(float start, float end, float alpha)
    {
        end -= start;
        alpha /= 1;
        float s = 1.70158f;
        return end * (alpha) * alpha * ((s + 1) * alpha - s) + start;
    }

    static float EaseOutBack(float start, float end, float alpha)
    {
        float s = 1.70158f;
        end -= start;
        alpha = (alpha) - 1;
        return end * ((alpha) * alpha * ((s + 1) * alpha + s) + 1) + start;
    }

    static float EaseInOutBack(float start, float end, float alpha)
    {
        float s = 1.70158f;
        end -= start;
        alpha /= 0.5f;
        if ((alpha) < 1)
        {
            s *= (1.525f);
            return end * 0.5f * (alpha * alpha * (((s) + 1) * alpha - s)) + start;
        }
        alpha -= 2;
        s *= (1.525f);
        return end * 0.5f * ((alpha) * alpha * (((s) + 1) * alpha + s) + 2) + start;
    }

    static float EaseInElastic(float start, float end, float alpha)
    {
        end -= start;

        float d = 1.0f;
        float p = d * 0.3f;
        float s;
        float a = 0;

        if (alpha == 0)
            return start;

        if ((alpha /= d) == 1)
            return start + end;

        if (a == 0.0f || a < std::abs(end))
        {
            a = end;
            s = p / 4;
        }
        else
            s = p / (2 * PI) * std::asin(end / a);

        return -(a * std::pow(2, 10 * (alpha -= 1)) * std::sin((alpha * d - s) * (2 * PI) / p)) + start;
    }

    static float EaseOutElastic(float start, float end, float alpha)
    {
        end -= start;

        float d = 1.0f;
        float p = d * 0.3f;
        float s;
        float a = 0;

        if (alpha == 0) return start;

        if ((alpha /= d) == 1) return start + end;

        if (a == 0.0f || a < std::abs(end))
        {
            a = end;
            s = p * 0.25f;
        }
        else
        {
            s = p / (2 * PI) * std::asin(end / a);
        }

        return (a * std::pow(2, -10 * alpha) * std::sin((alpha * d - s) * (2 * PI) / p) + end + start);
    }

    static float EaseInOutElastic(float start, float end, float alpha)
    {
        end -= start;

        float d = 1.0f;
        float p = d * 0.3f;
        float s;
        float a = 0;

        if (alpha == 0) return start;

        if ((alpha /= d * 0.5f) == 2) return start + end;

        if (a == 0.0f || a < std::abs(end))
        {
            a = end;
            s = p / 4;
        }
        else
        {
            s = p / (2 * PI) * std::asin(end / a);
        }

        if (alpha < 1) return -0.5f * (a * std::pow(2, 10 * (alpha -= 1)) * std::sin((alpha * d - s) * (2 * PI) / p)) + start;
        return a * std::pow(2, -10 * (alpha -= 1)) * std::sin((alpha * d - s) * (2 * PI) / p) * 0.5f + end + start;
    }

    //
    // These are derived functions that the motor can use to get the speed at a specific time.
    //
    // The easing functions all work with a normalized time (0 to 1) and the returned alpha here
    // reflects that. Values returned here should be divided by the actual time.
    //
    // TODO: These functions have not had the testing they deserve. If there is odd behavior around
    //       dash speeds then this would be the first place I'd look.

    template<typename T>
    static float LinearD(T start, T end, T alpha)
    {
        return end - start;
    }

    template<typename T>
    static float EaseInQuadD(T start, T end, T alpha)
    {
        return T(2.0f) * (end - start) * alpha;
    }

    template<typename T>
    static float EaseOutQuadD(T start, T end, T alpha)
    {
        end -= start;
        return -end * alpha - end * (alpha - T(2.0f));
    }

    static float EaseInOutQuadD(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;

        if (alpha < 1)
        {
            return end * alpha;
        }

        alpha--;

        return end * (1 - alpha);
    }

    static float EaseInCubicD(float start, float end, float alpha)
    {
        return  3.0f * (end - start) * alpha * alpha;
    }

    static float EaseOutCubicD(float start, float end, float alpha)
    {
        alpha--;
        end -= start;
        return 3.0f * end * alpha * alpha;
    }

    static float EaseInOutCubicD(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;

        if (alpha < 1)
        {
            return (3.0f / 2.0f) * end * alpha * alpha;
        }

        alpha -= 2;

        return (3.0f / 2.0f) * end * alpha * alpha;
    }

    static float EaseInQuartD(float start, float end, float alpha)
    {
        return 4.0f * (end - start) * alpha * alpha * alpha;
    }

    static float EaseOutQuartD(float start, float end, float alpha)
    {
        alpha--;
        end -= start;
        return -4.0f * end * alpha * alpha * alpha;
    }

    static float EaseInOutQuartD(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;

        if (alpha < 1)
        {
            return 2.0f * end * alpha * alpha * alpha;
        }

        alpha -= 2;

        return -2.0f * end * alpha * alpha * alpha;
    }

    static float EaseInQuintD(float start, float end, float alpha)
    {
        return 5.0f * (end - start) * alpha * alpha * alpha * alpha;
    }

    static float EaseOutQuintD(float start, float end, float alpha)
    {
        alpha--;
        end -= start;
        return 5.0f * end * alpha * alpha * alpha * alpha;
    }

    static float EaseInOutQuintD(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;

        if (alpha < 1)
        {
            return (5.0f / 2.0f) * end * alpha * alpha * alpha * alpha;
        }

        alpha -= 2;

        return (5.0f / 2.0f) * end * alpha * alpha * alpha * alpha;
    }

    static float EaseInSineD(float start, float end, float alpha)
    {
        return (end - start) * 0.5f * PI * std::sin(0.5f * PI * alpha);
    }

    static float EaseOutSineD(float start, float end, float alpha)
    {
        end -= start;
        return (PI * 0.5f) * end * std::cos(alpha * (PI * 0.5f));
    }

    static float EaseInOutSineD(float start, float end, float alpha)
    {
        end -= start;
        return end * 0.5f * PI * std::sin(PI * alpha);
    }

    static float EaseInExpoD(float start, float end, float alpha)
    {
        return 10.0f * NATURAL_LOG_OF_2 * (end - start) * std::pow(2.0f, 10.0f * (alpha - 1));
    }

    static float EaseOutExpoD(float start, float end, float alpha)
    {
        end -= start;
        return 5.0f * NATURAL_LOG_OF_2 * end * std::pow(2.0f, 1.0f - 10.0f * alpha);
    }

    static float EaseInOutExpoD(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;

        if (alpha < 1)
            return 5.0f * NATURAL_LOG_OF_2 * end * std::pow(2.0f, 10.0f * (alpha - 1));

        alpha--;

        return (5.0f * NATURAL_LOG_OF_2 * end) / (std::pow(2.0f, 10.0f * alpha));
    }

    static float EaseInCircD(float start, float end, float alpha)
    {
        return  (end - start) * alpha / std::sqrt(1.0f - alpha * alpha);
    }

    static float EaseOutCircD(float start, float end, float alpha)
    {
        alpha--;
        end -= start;
        return (-end * alpha) / std::sqrt(1.0f - alpha * alpha);
    }

    static float EaseInOutCircD(float start, float end, float alpha)
    {
        alpha /= 0.5f;
        end -= start;

        if (alpha < 1)
        {
            return (end * alpha) / (2.0f * std::sqrt(1.0f - alpha * alpha));
        }

        alpha -= 2;

        return (-end * alpha) / (2.0f * std::sqrt(1.0f - alpha * alpha));
    }

    static float EaseInBounceD(float start, float end, float alpha)
    {
        end -= start;
        float d = 1.0f;

        return EaseOutBounceD(0, end, d - alpha);
    }

    static float EaseOutBounceD(float start, float end, float alpha)
    {
        alpha /= 1.0f;
        end -= start;

        if (alpha < (1 / 2.75f))
        {
            return 2.0f * end * 7.5625f * alpha;
        }
        else if (alpha < (2 / 2.75f))
        {
            alpha -= (1.5f / 2.75f);
            return 2.0f * end * 7.5625f * alpha;
        }
        else if (alpha < (2.5 / 2.75))
        {
            alpha -= (2.25f / 2.75f);
            return 2.0f * end * 7.5625f * alpha;
        }
        else
        {
            alpha -= (2.625f / 2.75f);
            return 2.0f * end * 7.5625f * alpha;
        }
    }

    static float EaseInOutBounceD(float start, float end, float alpha)
    {
        end -= start;
        float d = 1.0f;

        return alpha < d * 0.5f ? EaseInBounceD(0, end, alpha * 2) * 0.5f : EaseOutBounceD(0, end, alpha * 2 - d) * 0.5f;
    }

    static float EaseInBackD(float start, float end, float alpha)
    {
        const float s = 1.70158f;
        return 3.0f * (s + 1.0f) * (end - start) * alpha * alpha - 2.0f * s * (end - start) * alpha;
    }

    static float EaseOutBackD(float start, float end, float alpha)
    {
        const float s = 1.70158f;
        end -= start;
        alpha = (alpha) - 1;

        return end * ((s + 1.0f) * alpha * alpha + 2.0f * alpha * ((s + 1.0f) * alpha + s));
    }

    static float EaseInOutBackD(float start, float end, float alpha)
    {
        float s = 1.70158f;
        end -= start;
        alpha /= 0.5f;

        if ((alpha) < 1)
        {
            s *= (1.525f);
            return 0.5f * end * (s + 1) * alpha * alpha + end * alpha * ((s + 1.0f) * alpha - s);
        }

        alpha -= 2;
        s *= (1.525f);
        return 0.5f * end * ((s + 1) * alpha * alpha + 2.0f * alpha * ((s + 1.0f) * alpha + s));
    }

    static float EaseInElasticD(float start, float end, float alpha)
    {
        return EaseOutElasticD(start, end, 1.0f - alpha);
    }

    static float EaseOutElasticD(float start, float end, float alpha)
    {
        end -= start;

        float d = 1.0f;
        float p = d * 0.3f;
        float s;
        float a = 0;

        if (a == 0.0f || a < std::abs(end))
        {
            a = end;
            s = p * 0.25f;
        }
        else
        {
            s = p / (2 * PI) * std::asin(end / a);
        }

        return (a * PI * d * std::pow(2.0f, 1.0f - 10.0f * alpha) *
            std::cos((2.0f * PI * (d * alpha - s)) / p)) / p - 5.0f * NATURAL_LOG_OF_2 * a *
            std::pow(2.0f, 1.0f - 10.0f * alpha) * std::sin((2.0f * PI * (d * alpha - s)) / p);
    }

    static float EaseInOutElasticD(float start, float end, float alpha)
    {
        end -= start;

        float d = 1.0f;
        float p = d * 0.3f;
        float s;
        float a = 0;

        if (a == 0.0f || a < std::abs(end))
        {
            a = end;
            s = p / 4;
        }
        else
        {
            s = p / (2 * PI) * std::asin(end / a);
        }

        if (alpha < 1)
        {
            alpha -= 1;

            return -5.0f * NATURAL_LOG_OF_2 * a * std::pow(2.0f, 10.0f * alpha) * std::sin(2 * PI * (d * alpha - 2.0f) / p) -
                a * PI * d * std::pow(2.0f, 10.0f * alpha) * std::cos(2 * PI * (d * alpha - s) / p) / p;
        }

        alpha -= 1;

        return a * PI * d * std::cos(2.0f * PI * (d * alpha - s) / p) / (p * std::pow(2.0f, 10.0f * alpha)) -
            5.0f * NATURAL_LOG_OF_2 * a * std::sin(2.0f * PI * (d * alpha - s) / p) / (std::pow(2.0f, 10.0f * alpha));
    }

    static float SpringD(float start, float end, float alpha)
    {
        alpha = Clamp(alpha, 0.0f, 1.0f);
        end -= start;

        // Damn... Thanks http://www.derivative-calculator.net/
        // TODO: And it's a little bit wrong
        return end * (6.0f * (1.0f - alpha) / 5.0f + 1.0f) * (-2.0f * std::pow(1.0f - alpha, 1.2f) *
            std::sin(PI * alpha * (2.5f * alpha * alpha * alpha + 0.2f)) + std::pow(1.0f - alpha, 2.2f) *
            (PI * (2.5f * alpha * alpha * alpha + 0.2f) + 7.5f * PI * alpha * alpha * alpha) *
            std::cos(PI * alpha * (2.5f * alpha * alpha * alpha + 0.2f)) + 1.0f) -
            6.0f * end * (std::pow(1 - alpha, 2.2f) * std::sin(PI * alpha * (2.5f * alpha * alpha * alpha + 0.2f)) + alpha
            / 5.0f);

    }
};