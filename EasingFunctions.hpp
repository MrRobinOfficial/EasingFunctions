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
 * from an enum. This is useful since the enum can be exposed in the editor and then the function queried during Start().
 * 
 * EasingFunction.Ease ease = EasingFunction.Ease.EaseInOutQuad;
 * EasingFunction.EasingFunc func = GetEasingFunction(ease;
 * 
 * float value = func(0, 10, 0.67f);
 * 
 * EasingFunction.EaseingFunc derivativeFunc = GetEasingFunctionDerivative(ease);
 * 
 * float derivativeValue = derivativeFunc(0, 10, 0.67f);
 */

class EasingFunction
{
    #define NATURAL_LOG_OF_2 0.693147181f;
    #define PI 3.14159274101257324219f

    enum EEaseType : unsigned int
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
    }

private:
    template<typename T>
    static T Lerp(const T& a, const T& b, const T& t)
    {
        return a * (T(1.0f) -t) + (b * t);
    }

    template<typename T>
    static T Pow(const T& base, const T& exponent)
    {
        T result = T(1.0f);

        for (T i = 0; i < exponent; ++i) {
            result *= base;
        }

        return result;
    }

    template<typename T>
    static T Sin(const T& x)
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
    static T Clamp(const T& value, const T& min, const T& max)
    {
        return value < min ? min : (value > max ? max : value);
    }

public:
    /// Easing functions ///

    template<typename T>
    static T Linear(const T& start, const T& end, const T& value)
    {
        return Lerp(start, end, value);
    }

    template<typename T>
    static T Spring(const T& start, const T& end, const T& value)
    {
        value = Clamp(value, T(0.0f), T(1.0f));
        value = (Sin(value * PI * (T(0.2f) + T(2.5f) * value * value * value)) * Pow(T(1f) - value, T(2.2f)) + value) * (T(1f) + (T(1.2f) * (1f - value)));

        return start + (end - start) * value;
    }

    template<typename T>
    static T EaseInQuad(const T& start, const T& end, const T& value)
    {
        end -= start;
        return end * value * value + start;
    }

    template<typename T>
    static T EaseOutQuad(const T& start, const T& end, const T& value)
    {
        end -= start;
        return -end * value * (value - T(2.0f)) + start;
    }

    template<typename T>
    static T EaseInOutQuad(const T& start, const T& end, const T& value)
    {
        value /= T(.5f);
        end -= start;
        if (value < T(1.0f)) return end * T(0.5f) * value * value + start;
        value--;
        return -end * T(0.5f) * (value * (value - T(2.0f)) - T(1.0f)) + start;
    }

    template<typename T>
    static float EaseInCubic(const T& start, const T& end, const T& value)
    {
        end -= start;
        return end * value * value * value + start;
    }

    template<typename T>
    static float EaseOutCubic(const T& start, const T& end, const T& value)
    {
        value--;
        end -= start;
        return end * (value * value * value + T(1.0f)) + start;
    }

    template<typename T>
    static float EaseInOutCubic(const T& start, const T& end, const T& value)
    {
        value /= T(0.5f);
        end -= start;
        if (value < T(1.0f)) return end * T(0.5f) * value * value * value + start;
        value -= T(2.0f);
        return end * T(0.5f) * (value * value * value + T(2.0f)) + start;
    }

    template<typename T>
    static float EaseInQuart(const T& start, const T& end, const T& value)
    {
        end -= start;
        return end * value * value * value * value + start;
    }

    template<typename T>
    static float EaseOutQuart(const T& start, const T& end, const T& value)
    {
        value--;
        end -= start;
        return -end * (value * value * value * value - T(1.0f)) + start;
    }

    static float EaseInOutQuart(float start, float end, float value)
    {
        value /= .5f;
        end -= start;
        if (value < 1) return end * 0.5f * value * value * value * value + start;
        value -= 2;
        return -end * 0.5f * (value * value * value * value - 2) + start;
    }

    static float EaseInQuint(float start, float end, float value)
    {
        end -= start;
        return end * value * value * value * value * value + start;
    }

    static float EaseOutQuint(float start, float end, float value)
    {
        value--;
        end -= start;
        return end * (value * value * value * value * value + 1) + start;
    }

    static float EaseInOutQuint(float start, float end, float value)
    {
        value /= .5f;
        end -= start;
        if (value < 1) return end * 0.5f * value * value * value * value * value + start;
        value -= 2;
        return end * 0.5f * (value * value * value * value * value + 2) + start;
    }

    static float EaseInSine(float start, float end, float value)
    {
        end -= start;
        return -end * Mathf.Cos(value * (Mathf.PI * 0.5f)) + end + start;
    }

    static float EaseOutSine(float start, float end, float value)
    {
        end -= start;
        return end * Mathf.Sin(value * (Mathf.PI * 0.5f)) + start;
    }

    static float EaseInOutSine(float start, float end, float value)
    {
        end -= start;
        return -end * 0.5f * (Mathf.Cos(Mathf.PI * value) - 1) + start;
    }

    static float EaseInExpo(float start, float end, float value)
    {
        end -= start;
        return end * Mathf.Pow(2, 10 * (value - 1)) + start;
    }

    static float EaseOutExpo(float start, float end, float value)
    {
        end -= start;
        return end * (-Mathf.Pow(2, -10 * value) + 1) + start;
    }

    static float EaseInOutExpo(float start, float end, float value)
    {
        value /= .5f;
        end -= start;

        if (value < 1)
            return end * 0.5f * Mathf.Pow(2, 10 * (value - 1)) + start;

        value--;

        return end * 0.5f * (-Mathf.Pow(2, -10 * value) + 2) + start;
    }

    static float EaseInCirc(float start, float end, float value)
    {
        end -= start;
        return -end * (Mathf.Sqrt(1 - value * value) - 1) + start;
    }

    static float EaseOutCirc(float start, float end, float value)
    {
        value--;
        end -= start;
        return end * Mathf.Sqrt(1 - value * value) + start;
    }

    static float EaseInOutCirc(float start, float end, float value)
    {
        value /= .5f;
        end -= start;
        if (value < 1) return -end * 0.5f * (Mathf.Sqrt(1 - value * value) - 1) + start;
        value -= 2;
        return end * 0.5f * (Mathf.Sqrt(1 - value * value) + 1) + start;
    }

    static float EaseInBounce(float start, float end, float value)
    {
        end -= start;
        float d = 1f;
        return end - EaseOutBounce(0, end, d - value) + start;
    }

    static float EaseOutBounce(float start, float end, float value)
    {
        value /= 1f;
        end -= start;
        if (value < (1 / 2.75f))
        {
            return end * (7.5625f * value * value) + start;
        }
        else if (value < (2 / 2.75f))
        {
            value -= (1.5f / 2.75f);
            return end * (7.5625f * (value) * value + .75f) + start;
        }
        else if (value < (2.5 / 2.75))
        {
            value -= (2.25f / 2.75f);
            return end * (7.5625f * (value) * value + .9375f) + start;
        }
        else
        {
            value -= (2.625f / 2.75f);
            return end * (7.5625f * (value) * value + .984375f) + start;
        }
    }

    static float EaseInOutBounce(float start, float end, float value)
    {
        end -= start;
        float d = 1f;
        if (value < d * 0.5f) return EaseInBounce(0, end, value * 2) * 0.5f + start;
        else return EaseOutBounce(0, end, value * 2 - d) * 0.5f + end * 0.5f + start;
    }

    static float EaseInBack(float start, float end, float value)
    {
        end -= start;
        value /= 1;
        float s = 1.70158f;
        return end * (value) * value * ((s + 1) * value - s) + start;
    }

    static float EaseOutBack(float start, float end, float value)
    {
        float s = 1.70158f;
        end -= start;
        value = (value) - 1;
        return end * ((value) * value * ((s + 1) * value + s) + 1) + start;
    }

    static float EaseInOutBack(float start, float end, float value)
    {
        float s = 1.70158f;
        end -= start;
        value /= .5f;
        if ((value) < 1)
        {
            s *= (1.525f);
            return end * 0.5f * (value * value * (((s) + 1) * value - s)) + start;
        }
        value -= 2;
        s *= (1.525f);
        return end * 0.5f * ((value) * value * (((s) + 1) * value + s) + 2) + start;
    }

    static float EaseInElastic(float start, float end, float value)
    {
        end -= start;

        float d = 1f;
        float p = d * .3f;
        float s;
        float a = 0;

        if (value == 0)
            return start;

        if ((value /= d) == 1)
            return start + end;

        if (a == 0f || a < Mathf.Abs(end))
        {
            a = end;
            s = p / 4;
        }
        else
            s = p / (2 * Mathf.PI) * Mathf.Asin(end / a);

        return -(a * Mathf.Pow(2, 10 * (value -= 1)) * Mathf.Sin((value * d - s) * (2 * Mathf.PI) / p)) + start;
    }

    static float EaseOutElastic(float start, float end, float value)
    {
        end -= start;

        float d = 1f;
        float p = d * .3f;
        float s;
        float a = 0;

        if (value == 0) return start;

        if ((value /= d) == 1) return start + end;

        if (a == 0f || a < Mathf.Abs(end))
        {
            a = end;
            s = p * 0.25f;
        }
        else
        {
            s = p / (2 * Mathf.PI) * Mathf.Asin(end / a);
        }

        return (a * Mathf.Pow(2, -10 * value) * Mathf.Sin((value * d - s) * (2 * Mathf.PI) / p) + end + start);
    }

    static float EaseInOutElastic(float start, float end, float value)
    {
        end -= start;

        float d = 1f;
        float p = d * .3f;
        float s;
        float a = 0;

        if (value == 0) return start;

        if ((value /= d * 0.5f) == 2) return start + end;

        if (a == 0f || a < Mathf.Abs(end))
        {
            a = end;
            s = p / 4;
        }
        else
        {
            s = p / (2 * Mathf.PI) * Mathf.Asin(end / a);
        }

        if (value < 1) return -0.5f * (a * Mathf.Pow(2, 10 * (value -= 1)) * Mathf.Sin((value * d - s) * (2 * Mathf.PI) / p)) + start;
        return a * Mathf.Pow(2, -10 * (value -= 1)) * Mathf.Sin((value * d - s) * (2 * Mathf.PI) / p) * 0.5f + end + start;
    }

    //
    // These are derived functions that the motor can use to get the speed at a specific time.
    //
    // The easing functions all work with a normalized time (0 to 1) and the returned value here
    // reflects that. Values returned here should be divided by the actual time.
    //
    // TODO: These functions have not had the testing they deserve. If there is odd behavior around
    //       dash speeds then this would be the first place I'd look.

    template<typename T>
    static float LinearD(const T& start, const T& end, const T& value)
    {
        return end - start;
    }

    template<typename T>
    static float EaseInQuadD(const T& start, const T& end, const T& value)
    {
        return T(2.0f) * (end - start) * value;
    }

    template<typename T>
    static float EaseOutQuadD(const T& start, const T& end, const T& value)
    {
        end -= start;
        return -end * value - end * (value - T(2.0f));
    }

    static float EaseInOutQuadD(float start, float end, float value)
    {
        value /= .5f;
        end -= start;

        if (value < 1)
        {
            return end * value;
        }

        value--;

        return end * (1 - value);
    }

    static float EaseInCubicD(float start, float end, float value) => 3f * (end - start) * value * value;

    static float EaseOutCubicD(float start, float end, float value)
    {
        value--;
        end -= start;
        return 3f * end * value * value;
    }

    static float EaseInOutCubicD(float start, float end, float value)
    {
        value /= .5f;
        end -= start;

        if (value < 1)
        {
            return (3f / 2f) * end * value * value;
        }

        value -= 2;

        return (3f / 2f) * end * value * value;
    }

    static float EaseInQuartD(float start, float end, float value)
    {
        return 4f * (end - start) * value * value * value;
    }

    static float EaseOutQuartD(float start, float end, float value)
    {
        value--;
        end -= start;
        return -4f * end * value * value * value;
    }

    static float EaseInOutQuartD(float start, float end, float value)
    {
        value /= .5f;
        end -= start;

        if (value < 1)
        {
            return 2f * end * value * value * value;
        }

        value -= 2;

        return -2f * end * value * value * value;
    }

    static float EaseInQuintD(float start, float end, float value)
    {
        return 5f * (end - start) * value * value * value * value;
    }

    static float EaseOutQuintD(float start, float end, float value)
    {
        value--;
        end -= start;
        return 5f * end * value * value * value * value;
    }

    static float EaseInOutQuintD(float start, float end, float value)
    {
        value /= .5f;
        end -= start;

        if (value < 1)
        {
            return (5f / 2f) * end * value * value * value * value;
        }

        value -= 2;

        return (5f / 2f) * end * value * value * value * value;
    }

    static float EaseInSineD(float start, float end, float value)
    {
        return (end - start) * 0.5f * Mathf.PI * Mathf.Sin(0.5f * Mathf.PI * value);
    }

    static float EaseOutSineD(float start, float end, float value)
    {
        end -= start;
        return (Mathf.PI * 0.5f) * end * Mathf.Cos(value * (Mathf.PI * 0.5f));
    }

    static float EaseInOutSineD(float start, float end, float value)
    {
        end -= start;
        return end * 0.5f * Mathf.PI * Mathf.Sin(Mathf.PI * value);
    }

    static float EaseInExpoD(float start, float end, float value) => 10f * NATURAL_LOG_OF_2 * (end - start) * Mathf.Pow(2f, 10f * (value - 1));

    static float EaseOutExpoD(float start, float end, float value)
    {
        end -= start;
        return 5f * NATURAL_LOG_OF_2 * end * Mathf.Pow(2f, 1f - 10f * value);
    }

    static float EaseInOutExpoD(float start, float end, float value)
    {
        value /= .5f;
        end -= start;

        if (value < 1)
            return 5f * NATURAL_LOG_OF_2 * end * Mathf.Pow(2f, 10f * (value - 1));

        value--;

        return (5f * NATURAL_LOG_OF_2 * end) / (Mathf.Pow(2f, 10f * value));
    }

    static float EaseInCircD(float start, float end, float value) => (end - start) * value / Mathf.Sqrt(1f - value * value);

    static float EaseOutCircD(float start, float end, float value)
    {
        value--;
        end -= start;
        return (-end * value) / Mathf.Sqrt(1f - value * value);
    }

    static float EaseInOutCircD(float start, float end, float value)
    {
        value /= .5f;
        end -= start;

        if (value < 1)
        {
            return (end * value) / (2f * Mathf.Sqrt(1f - value * value));
        }

        value -= 2;

        return (-end * value) / (2f * Mathf.Sqrt(1f - value * value));
    }

    static float EaseInBounceD(float start, float end, float value)
    {
        end -= start;
        float d = 1f;

        return EaseOutBounceD(0, end, d - value);
    }

    static float EaseOutBounceD(float start, float end, float value)
    {
        value /= 1f;
        end -= start;

        if (value < (1 / 2.75f))
        {
            return 2f * end * 7.5625f * value;
        }
        else if (value < (2 / 2.75f))
        {
            value -= (1.5f / 2.75f);
            return 2f * end * 7.5625f * value;
        }
        else if (value < (2.5 / 2.75))
        {
            value -= (2.25f / 2.75f);
            return 2f * end * 7.5625f * value;
        }
        else
        {
            value -= (2.625f / 2.75f);
            return 2f * end * 7.5625f * value;
        }
    }

    static float EaseInOutBounceD(float start, float end, float value)
    {
        end -= start;
        float d = 1f;

        return value < d * 0.5f ? EaseInBounceD(0, end, value * 2) * 0.5f : EaseOutBounceD(0, end, value * 2 - d) * 0.5f;
    }

    static float EaseInBackD(float start, float end, float value)
    {
        const float s = 1.70158f;
        return 3f * (s + 1f) * (end - start) * value * value - 2f * s * (end - start) * value;
    }

    static float EaseOutBackD(float start, float end, float value)
    {
        const float s = 1.70158f;
        end -= start;
        value = (value) - 1;

        return end * ((s + 1f) * value * value + 2f * value * ((s + 1f) * value + s));
    }

    static float EaseInOutBackD(float start, float end, float value)
    {
        float s = 1.70158f;
        end -= start;
        value /= .5f;

        if ((value) < 1)
        {
            s *= (1.525f);
            return 0.5f * end * (s + 1) * value * value + end * value * ((s + 1f) * value - s);
        }

        value -= 2;
        s *= (1.525f);
        return 0.5f * end * ((s + 1) * value * value + 2f * value * ((s + 1f) * value + s));
    }

    static float EaseInElasticD(float start, float end, float value)
    {
        return EaseOutElasticD(start, end, 1f - value);
    }

    static float EaseOutElasticD(float start, float end, float value)
    {
        end -= start;

        float d = 1f;
        float p = d * .3f;
        float s;
        float a = 0;

        if (a == 0f || a < Mathf.Abs(end))
        {
            a = end;
            s = p * 0.25f;
        }
        else
        {
            s = p / (2 * Mathf.PI) * Mathf.Asin(end / a);
        }

        return (a * Mathf.PI * d * Mathf.Pow(2f, 1f - 10f * value) *
            Mathf.Cos((2f * Mathf.PI * (d * value - s)) / p)) / p - 5f * NATURAL_LOG_OF_2 * a *
            Mathf.Pow(2f, 1f - 10f * value) * Mathf.Sin((2f * Mathf.PI * (d * value - s)) / p);
    }

    static float EaseInOutElasticD(float start, float end, float value)
    {
        end -= start;

        float d = 1f;
        float p = d * .3f;
        float s;
        float a = 0;

        if (a == 0f || a < Mathf.Abs(end))
        {
            a = end;
            s = p / 4;
        }
        else
        {
            s = p / (2 * Mathf.PI) * Mathf.Asin(end / a);
        }

        if (value < 1)
        {
            value -= 1;

            return -5f * NATURAL_LOG_OF_2 * a * Mathf.Pow(2f, 10f * value) * Mathf.Sin(2 * Mathf.PI * (d * value - 2f) / p) -
                a * Mathf.PI * d * Mathf.Pow(2f, 10f * value) * Mathf.Cos(2 * Mathf.PI * (d * value - s) / p) / p;
        }

        value -= 1;

        return a * Mathf.PI * d * Mathf.Cos(2f * Mathf.PI * (d * value - s) / p) / (p * Mathf.Pow(2f, 10f * value)) -
            5f * NATURAL_LOG_OF_2 * a * Mathf.Sin(2f * Mathf.PI * (d * value - s) / p) / (Mathf.Pow(2f, 10f * value));
    }

    static float SpringD(float start, float end, float value)
    {
        value = Mathf.Clamp01(value);
        end -= start;

        // Damn... Thanks http://www.derivative-calculator.net/
        // TODO: And it's a little bit wrong
        return end * (6f * (1f - value) / 5f + 1f) * (-2.2f * Mathf.Pow(1f - value, 1.2f) *
            Mathf.Sin(Mathf.PI * value * (2.5f * value * value * value + 0.2f)) + Mathf.Pow(1f - value, 2.2f) *
            (Mathf.PI * (2.5f * value * value * value + 0.2f) + 7.5f * Mathf.PI * value * value * value) *
            Mathf.Cos(Mathf.PI * value * (2.5f * value * value * value + 0.2f)) + 1f) -
            6f * end * (Mathf.Pow(1 - value, 2.2f) * Mathf.Sin(Mathf.PI * value * (2.5f * value * value * value + 0.2f)) + value
            / 5f);

    }

    template<typename T>
    delegate T Function(const T& start, const T& end, const T& value);

    /// <summary>
    /// Returns the function associated to the easingFunction enum. This value returned should be cached as it allocates memory
    /// to return.
    /// </summary>
    /// <param name="type">The enum associated with the easing function.</param>
    /// <returns>The easing function</returns>
    static Function GetEasingFunction(EEaseType type)
    {
        switch (type)
        {
            case EEaseType::EaseInQuad:
                return nullptr;

            default:
                return nullptr;
        }

        //         EaseType.EaseInQuad => EaseInQuad,
        // EaseType.EaseOutQuad => EaseOutQuad,
        // EaseType.EaseInOutQuad => EaseInOutQuad,
        // EaseType.EaseInCubic => EaseInCubic,
        // EaseType.EaseOutCubic => EaseOutCubic,
        // EaseType.EaseInOutCubic => EaseInOutCubic,
        // EaseType.EaseInQuart => EaseInQuart,
        // EaseType.EaseOutQuart => EaseOutQuart,
        // EaseType.EaseInOutQuart => EaseInOutQuart,
        // EaseType.EaseInQuint => EaseInQuint,
        // EaseType.EaseOutQuint => EaseOutQuint,
        // EaseType.EaseInOutQuint => EaseInOutQuint,
        // EaseType.EaseInSine => EaseInSine,
        // EaseType.EaseOutSine => EaseOutSine,
        // EaseType.EaseInOutSine => EaseInOutSine,
        // EaseType.EaseInExpo => EaseInExpo,
        // EaseType.EaseOutExpo => EaseOutExpo,
        // EaseType.EaseInOutExpo => EaseInOutExpo,
        // EaseType.EaseInCirc => EaseInCirc,
        // EaseType.EaseOutCirc => EaseOutCirc,
        // EaseType.EaseInOutCirc => EaseInOutCirc,
        // EaseType.Linear => Linear,
        // EaseType.Spring => Spring,
        // EaseType.EaseInBounce => EaseInBounce,
        // EaseType.EaseOutBounce => EaseOutBounce,
        // EaseType.EaseInOutBounce => EaseInOutBounce,
        // EaseType.EaseInBack => EaseInBack,
        // EaseType.EaseOutBack => EaseOutBack,
        // EaseType.EaseInOutBack => EaseInOutBack,
        // EaseType.EaseInElastic => EaseInElastic,
        // EaseType.EaseOutElastic => EaseOutElastic,
        // EaseType.EaseInOutElastic => EaseInOutElastic,
        // _ => null,
    }

    /// <summary>
    /// Gets the derivative function of the appropriate easing function. If you use an easing function for position then this
    /// function can get you the speed at a given time (normalized).
    /// </summary>
    /// <param name="type"></param>
    /// <returns>The derivative function</returns>
    static Function GetEasingFunctionDerivative(EEaseType type)
    {
        switch (type)
        {
            case EEaseType::EaseInQuad
                return nullptr;

            default:
                return nullptr;
        }

        //         EaseType.EaseInQuad => EaseInQuadD,
        // EaseType.EaseOutQuad => EaseOutQuadD,
        // EaseType.EaseInOutQuad => EaseInOutQuadD,
        // EaseType.EaseInCubic => EaseInCubicD,
        // EaseType.EaseOutCubic => EaseOutCubicD,
        // EaseType.EaseInOutCubic => EaseInOutCubicD,
        // EaseType.EaseInQuart => EaseInQuartD,
        // EaseType.EaseOutQuart => EaseOutQuartD,
        // EaseType.EaseInOutQuart => EaseInOutQuartD,
        // EaseType.EaseInQuint => EaseInQuintD,
        // EaseType.EaseOutQuint => EaseOutQuintD,
        // EaseType.EaseInOutQuint => EaseInOutQuintD,
        // EaseType.EaseInSine => EaseInSineD,
        // EaseType.EaseOutSine => EaseOutSineD,
        // EaseType.EaseInOutSine => EaseInOutSineD,
        // EaseType.EaseInExpo => EaseInExpoD,
        // EaseType.EaseOutExpo => EaseOutExpoD,
        // EaseType.EaseInOutExpo => EaseInOutExpoD,
        // EaseType.EaseInCirc => EaseInCircD,
        // EaseType.EaseOutCirc => EaseOutCircD,
        // EaseType.EaseInOutCirc => EaseInOutCircD,
        // EaseType.Linear => LinearD,
        // EaseType.Spring => SpringD,
        // EaseType.EaseInBounce => EaseInBounceD,
        // EaseType.EaseOutBounce => EaseOutBounceD,
        // EaseType.EaseInOutBounce => EaseInOutBounceD,
        // EaseType.EaseInBack => EaseInBackD,
        // EaseType.EaseOutBack => EaseOutBackD,
        // EaseType.EaseInOutBack => EaseInOutBackD,
        // EaseType.EaseInElastic => EaseInElasticD,
        // EaseType.EaseOutElastic => EaseOutElasticD,
        // EaseType.EaseInOutElastic => EaseInOutElasticD,
        // _ => null,
    }
}