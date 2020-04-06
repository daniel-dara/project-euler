import unittest
from unittest_data_provider import data_provider
from p052 import solve_problem_052


class Problem051Test(unittest.TestCase):
    @data_provider(lambda: (
        (2, 125874),
        (6, 142857),
    ))
    def test_solve(self, multiplier: int, expected: int):
        self.assertEqual(expected, solve_problem_052(multiplier))
