from unittest import TestCase

from .goldbachs_other_conjecture import solve


class TestSolution(TestCase):
    def test_solve(self):
        self.assertEqual(5777, solve())
