#!/usr/bin/env python3

from native_python.EasingFunctions import EasingFunctions as ef

import pytest

def approx_equal(a, b, places=3):
    """
    Approximate the equality of two floats.

    Args:
        a (float): The first float.
        b (float): The second float.
        places (int, optional): The number of decimal places to compare. Defaults to 3.

    Returns:
        bool: True if the two floats are approximately equal, False otherwise.
    """
    return round(a, places) == round(b, places)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5),
])
def test_ease(start, end, t, expected):
    assert approx_equal(ef.ease(ef.EaseType.Linear, start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5),
])
def test_lerp(start, end, t, expected):
    assert approx_equal(ef.lerp(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 1.0510158018655051),
])
def test_spring(start, end, t, expected):
    assert approx_equal(ef.spring(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.25),
])
def test_ease_in_quad(start, end, t, expected):
    assert approx_equal(ef.ease_in_quad(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5),
])
def test_ease_in_out_quad(start, end, t, expected):
    assert approx_equal(ef.ease_in_out_quad(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.125),
])
def test_ease_in_cubic(start, end, t, expected):
    assert approx_equal(ef.ease_in_cubic(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.875),
])
def test_ease_out_cubic(start, end, t, expected):
    assert approx_equal(ef.ease_out_cubic(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5),
])
def test_ease_in_out_cubic(start, end, t, expected):
    assert approx_equal(ef.ease_in_out_cubic(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.0625),
])
def test_ease_in_quart(start, end, t, expected):
    assert approx_equal(ef.ease_in_quart(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.9375),
])
def test_ease_out_quart(start, end, t, expected):
    assert approx_equal(ef.ease_out_quart(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5),
])
def test_ease_in_out_quart(start, end, t, expected):
    assert approx_equal(ef.ease_in_out_quart(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.03125),
])
def test_ease_in_quint(start, end, t, expected):
    assert approx_equal(ef.ease_in_quint(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.96875),
])
def test_ease_out_quint(start, end, t, expected):
    assert approx_equal(ef.ease_out_quint(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.2928932188134524),
])
def test_ease_in_sine(start, end, t, expected):
    assert approx_equal(ef.ease_in_sine(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.7071067811865476),
])
def test_ease_out_sine(start, end, t, expected):
    assert approx_equal(ef.ease_out_sine(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.49999999999999994),
])
def test_ease_in_out_sine(start, end, t, expected):
    assert approx_equal(ef.ease_in_out_sine(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0009765625),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.03125),
])
def test_ease_in_expo(start, end, t, expected):
    assert approx_equal(ef.ease_in_expo(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 0.9990234375),
    (0.0, 1.0, 0.5, 0.96875),
])
def test_ease_out_expo(start, end, t, expected):
    assert approx_equal(ef.ease_out_expo(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.1339745962155614),
])
def test_ease_in_circ(start, end, t, expected):
    assert approx_equal(ef.ease_in_circ(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.8660254037844386),
])
def test_ease_out_circ(start, end, t, expected):
    assert approx_equal(ef.ease_out_circ(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5),
])
def test_ease_in_out_circ(start, end, t, expected):
    assert approx_equal(ef.ease_in_out_circ(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5),
])
def test_ease_in_out_expo(start, end, t, expected):
    assert approx_equal(ef.ease_in_out_expo(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 2.0),
    (0.0, 1.0, 0.5, 0.734375),
])
def test_ease_in_bounce(start, end, t, expected):
    assert approx_equal(ef.ease_in_bounce(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.765625),
])
def test_ease_out_bounce(start, end, t, expected):
    assert approx_equal(ef.ease_out_bounce(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5),
])
def test_ease_in_out_bounce(start, end, t, expected):
    assert approx_equal(ef.ease_in_out_bounce(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, -0.08769750000000004),
])
def test_ease_in_back(start, end, t, expected):
    assert approx_equal(ef.ease_in_back(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 1.0876975),
])
def test_ease_out_back(start, end, t, expected):
    assert approx_equal(ef.ease_out_back(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5),
])
def test_ease_in_out_back(start, end, t, expected):
    assert approx_equal(ef.ease_in_out_back(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, -0.023223275796168532),
])
def test_ease_in_elastic(start, end, t, expected):
    assert approx_equal(ef.ease_in_elastic(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 1.015625),
])
def test_ease_out_elastic(start, end, t, expected):
    assert approx_equal(ef.ease_out_elastic(start, end, t), expected)

@pytest.mark.parametrize("start, end, t, expected", [
    (0.0, 1.0, 0.0, 0.0),
    (0.0, 1.0, 1.0, 1.0),
    (0.0, 1.0, 0.5, 0.5244717418524232),
])
def test_ease_in_out_elastic(start, end, t, expected):
    assert approx_equal(ef.ease_in_out_elastic(start, end, t), expected)
