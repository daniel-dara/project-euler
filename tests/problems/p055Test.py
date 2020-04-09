import unittest
from unittest_data_provider import data_provider
from problems.p055 import solve_problem_055, is_lychrel


class Problem055Test(unittest.TestCase):
    @data_provider(lambda: (
        (249,),
    ))
    def test_solve(self, expected: int):
        self.assertEqual(expected, solve_problem_055())

    @data_provider(lambda: (
        (47, False),
        (349, False),
        (10677, True),  # Lychrel based on problem statement
    ))
    def test_is_lychrel(self, number: int, expected: bool):
        self.assertEqual(expected, is_lychrel(number))
