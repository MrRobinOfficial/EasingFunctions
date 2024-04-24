#!/usr/bin/env python3

"""
Easing Functions that can be used in animations, video games, and other scenarios.
The library includes a set of easing functions mainly: lerp, ease in, ease out, etc.
"""

from enum import Enum
import math

class EasingFunctions:
    """
    Class that contains all easing functions.
    """

    class EaseType(Enum):
        """
        Types of eases methods
        """
        Linear = 0
        Spring = 1
        EaseInQuad = 2
        EaseOutQuad = 3
        EaseInOutQuad = 4
        EaseInCubic = 5
        EaseOutCubic = 6
        EaseInOutCubic = 7
        EaseInQuart = 8
        EaseOutQuart = 9
        EaseInOutQuart = 10
        EaseInQuint = 11
        EaseOutQuint = 12
        EaseInOutQuint = 13
        EaseInSine = 14
        EaseOutSine = 15
        EaseInOutSine = 16
        EaseInExpo = 17
        EaseOutExpo = 18
        EaseInOutExpo = 19
        EaseInCirc = 20
        EaseOutCirc = 21
        EaseInOutCirc = 22
        EaseInBounce = 23
        EaseOutBounce = 24
        EaseInOutBounce = 25
        EaseInBack = 26
        EaseOutBack = 27
        EaseInOutBack = 28
        EaseInElastic = 29
        EaseOutElastic = 30
        EaseInOutElastic = 31

    @staticmethod
    def epsilon() -> float:
        """
        Returns the smallest representable positive number such that
        1.0 + epsilon != 1.0.

        This value is often used as a threshold for determining whether
        a float is zero or not.
        """
        import sys
        return sys.float_info.epsilon

    @staticmethod
    def clamp(value: float, min_value: float = 0.0, max_value: float = 1.0) -> float:
        return min(max(value, min_value), max_value)

    @staticmethod
    def ease(type: EaseType, a: float, b: float, t: float) -> float:
        """
        Ease between a and b using the t and the given type.
        """
        return {
            EasingFunctions.EaseType.Linear: EasingFunctions.lerp,
            EasingFunctions.EaseType.Spring: EasingFunctions.spring,
            EasingFunctions.EaseType.EaseInQuad: EasingFunctions.ease_in_quad,
            EasingFunctions.EaseType.EaseOutQuad: EasingFunctions.ease_out_quad,
            EasingFunctions.EaseType.EaseInOutQuad: EasingFunctions.ease_in_out_quad,
            EasingFunctions.EaseType.EaseInCubic: EasingFunctions.ease_in_cubic,
            EasingFunctions.EaseType.EaseOutCubic: EasingFunctions.ease_out_cubic,
            EasingFunctions.EaseType.EaseInOutCubic: EasingFunctions.ease_in_out_cubic,
            EasingFunctions.EaseType.EaseInQuart: EasingFunctions.ease_in_quart,
            EasingFunctions.EaseType.EaseOutQuart: EasingFunctions.ease_out_quart,
            EasingFunctions.EaseType.EaseInOutQuart: EasingFunctions.ease_in_out_quart,
            EasingFunctions.EaseType.EaseInQuint: EasingFunctions.ease_in_quint,
            EasingFunctions.EaseType.EaseOutQuint: EasingFunctions.ease_out_quint,
            EasingFunctions.EaseType.EaseInOutQuint: EasingFunctions.ease_in_out_quint,
            EasingFunctions.EaseType.EaseInSine: EasingFunctions.ease_in_sine,
            EasingFunctions.EaseType.EaseOutSine: EasingFunctions.ease_out_sine,
            EasingFunctions.EaseType.EaseInOutSine: EasingFunctions.ease_in_out_sine,
            EasingFunctions.EaseType.EaseInExpo: EasingFunctions.ease_in_expo,
            EasingFunctions.EaseType.EaseOutExpo: EasingFunctions.ease_out_expo,
            EasingFunctions.EaseType.EaseInOutExpo: EasingFunctions.ease_in_out_expo,
            EasingFunctions.EaseType.EaseInCirc: EasingFunctions.ease_in_circ,
            EasingFunctions.EaseType.EaseOutCirc: EasingFunctions.ease_out_circ,
            EasingFunctions.EaseType.EaseInOutCirc: EasingFunctions.ease_in_out_circ,
            EasingFunctions.EaseType.EaseInBounce: EasingFunctions.ease_in_bounce,
            EasingFunctions.EaseType.EaseOutBounce: EasingFunctions.ease_out_bounce,
            EasingFunctions.EaseType.EaseInOutBounce: EasingFunctions.ease_in_out_bounce,
            EasingFunctions.EaseType.EaseInBack: EasingFunctions.ease_in_back,
            EasingFunctions.EaseType.EaseOutBack: EasingFunctions.ease_out_back,
            EasingFunctions.EaseType.EaseInOutBack: EasingFunctions.ease_in_out_back,
            EasingFunctions.EaseType.EaseInElastic: EasingFunctions.ease_in_elastic,
            EasingFunctions.EaseType.EaseOutElastic: EasingFunctions.ease_out_elastic,
            EasingFunctions.EaseType.EaseInOutElastic: EasingFunctions.ease_in_out_elastic,
        }[type](a, b, t)

    @staticmethod
    def lerp(a: float, b: float, t: float, clamp: bool = True) -> float:
        """
        Linear interpolation between a and b using t.

        The function returns a value between a and b,
        inclusive. If clamp is True, the function clamps
        t to the range [0.0, 1.0].
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        return (b - a) * t + a

    @staticmethod
    def spring(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Spring easing function.

        The function starts and ends at 0.0, and accelerates
        towards the desired value. The function is clamped,
        so the return value will always be between start and
        end, inclusive.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        value = (math.sin(t * math.pi * (0.2 + 2.5 * t * t * t)) *
                 math.pow(1 - t, 2.2) + t) * (1 + (1.2 * (1 - t)))

        return start + (end - start) * value

    @staticmethod
    def ease_in_quad(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using a quadratic function.

        The function starts at 0.0, and accelerates towards
        the desired value. The function is clamped, so the
        return value will always be between start and end,
        inclusive.
        """
        if clamp:
            t = EasingFunctions.clamp(t)
    
        end -= start
        return end * t ** 2 + start

    @staticmethod
    def ease_out_quad(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using a quadratic function.

        The function starts at the desired value, and decelerates
        to 0.0. The function is clamped, so the return value will
        always be between start and end, inclusive.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return -end * t * (t - 2.0) + start

    @staticmethod
    def ease_in_out_quad(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using a quadratic function.

        The function starts and ends at 0.0, and accelerates
        towards the desired value. The function is clamped,
        so the return value will always be between start and
        end, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        t /= 0.5
        end -= start

        if t < 1.0:
            return end * 0.5 * t * t + start

        t = t - 1.0

        return -end * 0.5 * (t * (t - 2.0) - 1.0) + start

    @staticmethod
    def ease_in_cubic(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using a cubic function.

        The function starts at 0.0 and accelerates quickly to
        the desired value. The function is clamped, so the return
        value will always be between start and end, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return end * t ** 3 + start

    @staticmethod
    def ease_out_cubic(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using a cubic function.

        The function starts at the desired value and decelerates
        slowly towards 0.0. The function is clamped, so the return
        value will always be between start and 0.0, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        t = t - 1.0
        end -= start
        return end * (t ** 3 + 1.0) + start

    @staticmethod
    def ease_in_out_cubic(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using a cubic function.

        The function starts and ends at 0.0, and accelerates
        towards the desired value. The function is clamped,
        so the return value will always be between start and
        end, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        t /= 0.5
        end -= start

        if t < 1.0:
            return end * 0.5 * t ** 3 + start

        t -= 2.0
        return end * 0.5 * (t ** 3 + 2) + start

    @staticmethod
    def ease_in_quart(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using a quartic function.

        The function starts at 0.0, accelerates towards the
        desired value, and ends at the desired value.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return end * t ** 4 + start

    @staticmethod
    def ease_out_quart(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using a quartic function.

        The function starts at the desired value, decelerates
        towards 0.0, and ends at 0.0. The function is clamped,
        so the return value will always be between start and
        0.0, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        t = t - 1
        end -= start
        return -end * (t ** 4 - 1) + start

    @staticmethod
    def ease_in_out_quart(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using a quartic function.

        The function starts and ends at 0.0, and accelerates
        towards the desired value. The function is clamped,
        so the return value will always be between start and
        end, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        t /= 0.5
        end -= start

        if t < 1.0:
            return end * 0.5 * t ** 4 + start

        t -= 2.0
        return -end * 0.5 * (t ** 4 - 2) + start

    @staticmethod
    def ease_in_quint(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using a quintic function.

        The function starts at 0.0, accelerates towards the
        desired value, and ends at the desired value.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return end * t ** 5 + start

    @staticmethod
    def ease_out_quint(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using a quintic function.

        The function starts at the desired value, decelerates
        towards 0.0, and ends at 0.0. The function is clamped,
        so the return value will always be between start and
        0.0, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        t = t - 1.0
        end -= start
        return end * (t ** 5 + 1) + start

    @staticmethod
    def ease_in_out_quint(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using a quintic function.

        The function starts and ends at 0.0, and accelerates
        towards the desired value. The function is clamped,
        so the return value will always be between start and
        end, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        t /= 0.5
        end -= start
        if t < 1.0:
            return end * 0.5 * t ** 5 + start
        t -= 2.0
        return end * 0.5 * (t ** 5 + 2) + start

    @staticmethod
    def ease_in_sine(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using a sine wave.

        The function starts at 0.0, and accelerates towards
        the desired value. The function is clamped, so the
        return value will always be between start and end,
        inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return -end * math.cos(t * (math.pi * 0.5)) + end + start

    @staticmethod
    def ease_out_sine(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using a sine wave.

        The function starts at the desired value, decelerates
        towards 0.0, and ends at 0.0. The function is clamped,
        so the return value will always be between start and
        0.0, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return end * math.sin(t * (math.pi * 0.5)) + start

    @staticmethod
    def ease_in_out_sine(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using a sine wave.

        The function starts and ends at 0.0, and accelerates
        towards the desired value using a sine wave. The
        function is clamped, so the return value will always
        be between start and end, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return -end * 0.5 * (math.cos(math.pi * t) - 1.0) + start

    @staticmethod
    def ease_in_expo(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using an exponential function.

        The function starts at 0.0, and accelerates towards
        the desired value. The function is clamped, so the
        return value will always be between start and end,
        inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return end * math.pow(2.0, 10.0 * (t - 1.0)) + start

    @staticmethod
    def ease_out_expo(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using an exponential function.

        The function starts at the desired value, decelerates
        towards 0.0, and ends at 0.0. The function is clamped,
        so the return value will always be between start and
        0.0, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return end * (-math.pow(2.0, -10.0 * t) + 1.0) + start

    @staticmethod
    def ease_in_out_expo(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using an exponential function.

        The function starts and ends at 0.0, and accelerates
        towards the desired value using an exponential
        function. The function is clamped, so the return value
        will always be between start and end, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        t /= 0.5
        end -= start

        if t < 1.0:
            return end * 0.5 * math.pow(2.0, 10.0 * (t - 1.0)) + start
    
        t = t - 1
        return end * 0.5 * (-math.pow(2.0, -10.0 * t) + 2.0) + start

    @staticmethod
    def ease_in_circ(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using a circular function.

        The function starts at 0.0, and accelerates towards
        the desired value. The function is clamped, so the
        return value will always be between start and end,
        inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return -end * (math.sqrt(1.0 - t * t) - 1.0) + start

    @staticmethod
    def ease_out_circ(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using a circular function.

        The function starts at the desired value, decelerates
        towards 0.0, and ends at 0.0. The function is clamped,
        so the return value will always be between start and
        0.0, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)
    
        t = t - 1.0
        end -= start
        return end * math.sqrt(1.0 - t * t) + start

    @staticmethod
    def ease_in_out_circ(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using a circular function.

        The function starts and ends at 0.0, and accelerates
        towards the desired value using a circular function.
        The function is clamped, so the return value will always
        be between start and end, inclusive.

        The function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        t /= 0.5
        end -= start

        if t < 1.0:
            return -end * 0.5 * (math.sqrt(1.0 - t * t) - 1.0) + start

        t -= 2.0

        return end * 0.5 * (math.sqrt(1.0 - t * t) + 1) + start

    @staticmethod
    def ease_in_bounce(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using a bounce function.

        The function starts at 0.0, and accelerates towards
        the desired value. The function is clamped, so the
        return value will always be between start and
        end, inclusive. The function takes the starting
        value, ending value, and time from 0.0 to 1.0 as
        input, and returns the interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        return end - EasingFunctions.ease_out_bounce(0, end, 1.0 - t) + t

    @staticmethod
    def ease_out_bounce(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using a bounce function.

        The function starts at the desired value, decelerates
        towards 0.0, and ends at 0.0. The function is clamped,
        so the return value will always be between start and
        0.0, inclusive. The function takes the starting value,
        ending value, and time from 0.0 to 1.0 as input,
        and returns the interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)
        
        t /= 1.0
        end -= start

        if t < (1.0 / 2.75):
            return end * (7.5625 * t * t) + start

        if t < (2.0 / 2.75):
            t -= 1.5 / 2.75
            return end * (7.5625 * t * t + 0.75) + start

        if t < (2.5 / 2.75):
            t -= 2.25 / 2.75
            return end * (7.5625 * t * t + 0.9375) + start

        t -= 2.625 / 2.75
        return end * (7.5625 * t * t + 0.984375) + start

    @staticmethod
    def ease_in_out_bounce(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using a bounce function.

        The function starts and ends at 0.0, and accelerates
        towards the desired value using a bounce function.
        The function is clamped, so the return value will always
        be between start and end, inclusive. The function takes
        the starting value, ending value, and time from 0.0 to
        1.0 as input, and returns the interpolated value at
        that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start

        if t < 1.0 * 0.5:
            return EasingFunctions.ease_in_bounce(0, end, t * 2.0) * 0.5 + start

        return EasingFunctions.ease_out_bounce(0, end, t * 2.0 - 1.0) * 0.5 + end * 0.5 + start

    @staticmethod
    def ease_in_back(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using a back function.

        The function starts at 0.0, and accelerates towards
        the desired value using a back function. The function
        is clamped, so the return value will always be between
        start and end, inclusive. The function takes the
        starting value, ending value, and time from 0.0 to
        1.0 as input, and returns the interpolated value at
        that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        t /= 1.0

        # The strength of the back function. Higher values
        # result in a steeper ease-in.
        s = 1.70158
        return end * t ** 2 * ((s + 1.0) * t - s) + start

    @staticmethod
    def ease_out_back(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using a back function.

        The function starts at the desired value, and
        decelerates towards 0.0 using a back function. The
        function is clamped, so the return value will always
        be between start and end, inclusive. The function
        takes the starting value, ending value, and time from
        0.0 to 1.0 as input, and returns the interpolated
        value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        t -= 1.0

        s = 1.70158
        return end * ((t) * t * ((s + 1.0) * t + s) + 1.0) + start

    @staticmethod
    def ease_in_out_back(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using a back function.

        The function starts and ends at 0.0, and accelerates
        towards the desired value using a back function.
        The function is clamped, so the return value will
        always be between start and end, inclusive. The
        function takes the starting value, ending value,
        and time from 0.0 to 1.0 as input, and returns the
        interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        end -= start
        t /= 0.5

        s = 1.70158

        if t < 1.0:
            s *= 1.525
            return end * 0.5 * (t ** 2 * (((s) + 1.0) * t - s)) + start

        t -= 2.0
        s *= 1.525
        
        return end * 0.5 * ((t) * t * (((s) + 1.0) * t + s) + 2.0) + start

    @staticmethod
    def ease_in_elastic(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in using an elastic function.

        The function starts at 0.0, accelerates towards the
        desired value using a parabolic function, and ends at
        the desired value. The function is clamped, so the
        return value will always be between start and end,
        inclusive. The function takes the starting value,
        ending value, and time from 0.0 to 1.0 as input, and
        returns the interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        # Constants
        d = 1.0
        p = d * 0.3

        # Precompute a few values for the function
        end -= start

        # The function is linear for t close to 0.0
        if abs(t) < EasingFunctions.epsilon():
            return start

        # Scale time to 0.0 - 1.0
        t /= d

        # The function is linear for t close to 1.0
        if abs(t - 1.0) < EasingFunctions.epsilon():
            return start + end

        # Amplitude and period
        a = 0.0
        s = 0.0

        # If the amplitude is 0.0 or less or greater than the
        # change in value, we use the change in value directly
        if abs(a) < EasingFunctions.epsilon() or a < abs(end):
            a = end
            s = p * 0.2
        else:
            s = p / (2.0 * math.pi) * math.asin(end / a)

        # Decrement time
        t -= 1.0

        # Return the interpolated value
        return -(a * math.pow(2.0, 10.0 * (t)) * math.sin((t * d - s) * (2.0 * math.pi) / p)) + start

    @staticmethod
    def ease_out_elastic(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases out using an elastic function.

        The function starts at the desired value, decelerates
        towards 0.0, and ends at 0.0. The function is clamped,
        so the return value will always be between start and
        0.0, inclusive. The function takes the starting value,
        ending value, and time from 0.0 to 1.0 as input, and
        returns the interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        # Constants
        d = 1.0
        p = d * 0.3

        # Precompute a few values for the function
        end -= start

        # The function is linear for t close to 0.0
        if abs(t) < EasingFunctions.epsilon():
            return start

        # Scale time to 0.0 - 1.0
        t /= d

        # The function is linear for t close to 1.0
        if abs(t - 1.0) < EasingFunctions.epsilon():
            return start + end

        # Amplitude and period
        a = 0.0
        s = 0.0

        # If the amplitude is 0.0 or less or greater than the
        # change in value, we use the change in value directly
        if abs(a) < EasingFunctions.epsilon() or a < abs(end):
            a = end
            s = p * 0.25
        else:
            s = p / (2.0 * math.pi) * math.asin(end / a)

        # Return the interpolated value
        return a * math.pow(2.0, -10.0 * t) * math.sin((t * d - s) * (2.0 * math.pi) / p) + end + start

    @staticmethod
    def ease_in_out_elastic(start: float, end: float, t: float, clamp: bool = True) -> float:
        """
        Eases in and out using an elastic function.

        The function starts and ends at the desired value,
        accelerates towards the end value using a parabolic
        function, and decelerates towards the start value
        using a parabolic function. The function is clamped,
        so the return value will always be between start and
        end, inclusive. The function takes the starting value,
        ending value, and time from 0.0 to 1.0 as input, and
        returns the interpolated value at that time.
        """
        if clamp:
            t = EasingFunctions.clamp(t)

        # Constants
        d = 1.0
        p = d * 0.3

        # Precompute a few values for the function
        s = 0.0
        a = 0.0

        end -= start

        # The function is linear for t close to 0.0
        if abs(t) < EasingFunctions.epsilon():
            return start

        t /= d * 0.5

        # The function is linear for t close to 1.0
        if abs(t - 2.0) < EasingFunctions.epsilon():
            return start + end

        # Amplitude and period
        if abs(a) < EasingFunctions.epsilon() or a < abs(end):
            a = end
            s = p * 0.2
        else:
            s = p / (2 * math.pi) * math.asin(end / a)

        # The first half of the elastic function
        if t < 1.0:
            t -= 1
            return -0.5 * (a * math.pow(2.0, 10.0 * t) * math.sin((t * d - s) * 
                (2.0 * math.pi) / p)) + start

        # The second half of the elastic function
        t -= 1
        return a * math.pow(2, -10.0 * t) * math.sin((t * d - s) *
                (2 * math.pi) / p) * 0.5 + end + start
