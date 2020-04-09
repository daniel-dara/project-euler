import unittest
from unittest_data_provider import data_provider
from problems.p053 import solve_problem_053


class Problem053Test(unittest.TestCase):
    @data_provider(lambda: (
        (4075,),
    ))
    def test_solve(self, expected: int):
        self.assertEqual(expected, solve_problem_053())
