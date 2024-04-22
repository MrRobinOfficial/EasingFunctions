#!/usr/bin/env python3

"""
Easing Functions
"""

from enum import Enum
import math

class EasingFunction:
    """
    Hello, World!
    """
    class EaseType(Enum):
        """
        Hello, World!
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
    def lerp(a: float, b: float, t: float) -> float:
        """
        Linear interpolate on the scale given by a to b, using t as the point on that scale.
        """
        return (1.0 - t) * a + t * b

    @staticmethod
    def linear(start: float, end: float, t: float) -> float:
        """
        Hello World
        """
        t = min(max(t, 0.0), 1.0)
        return EasingFunction.lerp(start, end, t)

    @staticmethod
    def spring(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        t = (math.sin(t * math.pi * (0.2 + 2.5 * t * t * t)) * math.pow(1.0 - t, 2.2) + t) * (1.0 + (1.2 * (1.0 - t)))
        return start + (end - start)  * t

    @staticmethod
    def ease_in_quad(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return end * t * t + start

    @staticmethod
    def ease_out_quad(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return -end * t * (t - 2) + start

    @staticmethod
    def ease_in_out_quad(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        t /= 0.5
        if t < 1.0: return end * 0.5 * t * t + start
        end -= start
        t = t - 1.0
        return -end * 0.5 * (t * (t - 2.0) - 1.0) + start

    @staticmethod
    def ease_in_cubic(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return end * t ** 3 + start

    @staticmethod
    def ease_out_cubic(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        t = t - 1.0
        end -= start
        return end * (t ** 3 + 1.0) + start

    @staticmethod
    def ease_in_out_cubic(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        t /= 0.5
        end -= start
        if t < 1.0: return end * 0.5 * t ** 3 + start
        t -= 2.0
        return end * 0.5 * (t ** 3 + 2) + start

    @staticmethod
    def ease_in_quart(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return end * t ** 4 + start

    @staticmethod
    def ease_out_quart(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        t = t - 1
        end -= start
        return -end * (t ** 4 - 1) + start

    @staticmethod
    def ease_in_out_quart(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        t /= 0.5
        end -= start
        if t < 1.0: return end * 0.5 * t ** 4 + start
        t -= 2.0
        return -end * 0.5 * (t ** 4 - 2) + start

    @staticmethod
    def ease_in_quint(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return end * t ** 5 + start

    @staticmethod
    def ease_out_quint(start: float, end: float, t: float) -> float:
        """
        Hello, World!
        """
        t = min(max(t, 0.0), 1.0)
        t = t - 1.0
        end -= start
        return end * (t ** 5 + 1) + start

    @staticmethod
    def ease_in_out_quint(start: float, end: float, t: float) -> float:
        """
        Eases in and out by raising the fraction to the power of 5.
        """
        t = min(max(t, 0.0), 1.0)
        t /= 0.5
        end -= start
        if t < 1.0: return end * 0.5 * t ** 5 + start
        t -= 2.0
        return end * 0.5 * (t ** 5 + 2) + start

    @staticmethod
    def ease_in_sine(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return -end * math.cos(t * (math.pi * 0.5)) + end + start

    @staticmethod
    def ease_out_sine(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return end * math.sin(t * (math.pi * 0.5)) + start

    @staticmethod
    def ease_in_out_sine(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return -end * 0.5 * (math.cos(math.pi * t) - 1.0) + start

    @staticmethod
    def ease_in_expo(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return end * math.pow(2.0, 10.0 * (t - 1.0)) + start

    @staticmethod
    def ease_out_expo(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return end * (-math.pow(2.0, -10.0 * t) + 1.0) + start

    @staticmethod
    def ease_in_out_expo(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        t /= 0.5
        end -= start
        if t < 1.0: return end * 0.5 * math.pow(2.0, 10.0 * (t - 1.0)) + start
        t = t - 1
        return end * 0.5 * (-math.pow(2.0, -10.0 * t) + 2.0) + start

    @staticmethod
    def ease_in_circ(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        return -end * (math.sqrt(1.0 - t * t) - 1.0) + start

    @staticmethod
    def ease_out_circ(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        t = t - 1.0
        end -= start
        return end * math.sqrt(1.0 - t * t) + start

    @staticmethod
    def ease_in_out_circ(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        t /= 0.5
        end -= start
        if t < 1.0: return -end * 0.5 * (math.sqrt(1.0 - t * t) - 1.0) + start
        t -= 2.0
        return end * 0.5 * (math.sqrt(1.0 - t * t) + 1) + start

    @staticmethod
    def ease_in_bounce(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        end -= start
        d = 1.0
        return end - EasingFunction.ease_out_bounce(0.0, end, d - t) + start

    @staticmethod
    def ease_out_bounce(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        t /= 1.0
        end -= start

        if t < (1.0 / 2.75):
            return end * (7.5625 * t * t) + start
        elif t < (2.0 / 2.75):
            t -= (1.5 / 2.75)
            return end * (7.5625 * t * t + 0.75) + start
        elif t < (2.5 / 2.75):
            t -= (2.25 / 2.75)
            return end * (7.5625 * t * t + 0.9375) + start
        else:
            t -= (2.625 / 2.75)
            return end * (7.5625 * t * t + 0.984375) + start

    def ease_in_out_bounce(start: float, end: float, t: float) -> float:
        """
        Eases in using math.sin.
        """
        t = min(max(t, 0.0), 1.0)
        end -= start;
        d = 1.0;
        if t < d * 0.5:
            return EasingFunction.ease_in_bounce(0.0, end, t * 2.0) * 0.5 + start
        else:
            return EasingFunction.ease_out_bounce(0.0, end, t * 2.0 - d) * 0.5 + end * 0.5 + start
