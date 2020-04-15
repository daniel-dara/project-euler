from unittest import TestCase

from .spiral_primes import solve


class TestSolution(TestCase):
    def test_solve(self):
        self.assertEqual(26241, solve())
