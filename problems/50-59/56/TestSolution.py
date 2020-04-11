from unittest import TestCase

from .powerful_digit_sum import solve


class TestSolution(TestCase):
    def test_solve(self):
        self.assertEqual(972, solve())
