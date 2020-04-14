from typing import Tuple
from unittest import TestCase

from unittest_data_provider import data_provider

from .square_root_convergents import solve, expand


class TestSolution(TestCase):
    def test_solve(self):
        self.assertEqual(153, solve())

    @data_provider(lambda: (
        (0, (3, 2)),
        (1, (7, 5)),
        (2, (17, 12)),
        (3, (41, 29)),
        (4, (99, 70)),
        (5, (239, 169)),
        (6, (577, 408)),
        (7, (1393, 985)),
    ))
    def test_expand(self, n: int, expected_fraction: Tuple[int, int]):
        self.assertEqual(expected_fraction, expand(n))
