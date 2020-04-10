from unittest import TestCase

from .prime_permutations import solve, find_all_sequences


class TestSolution(TestCase):
    def test_find_all_sequences(self):
        self.assertEqual([(1487, 4817, 8147), (2969, 6299, 9629)], find_all_sequences())

    def test_solve(self):
        self.assertEqual(296962999629, solve())
