from unittest import TestCase
from unittest_data_provider import data_provider

from .permuted_multiples import solve


class TestSolution(TestCase):
    @data_provider(lambda: (
        (2, 125874),  # Example 1
        (6, 142857),  # Problem
    ))
    def test_solve(self, multiplier: int, expected_smallest_int: int):
        self.assertEqual(expected_smallest_int, solve(multiplier))
