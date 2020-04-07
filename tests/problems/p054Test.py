import unittest
from unittest_data_provider import data_provider
from p054 import solve_problem_054


class Problem054Test(unittest.TestCase):
    @data_provider(lambda: (
        ('../../p054.example.in', 3),
        ('../../p054.in', 376),
    ))
    def test_solve(self, file_name: str, expected: int):
        self.assertEqual(expected, solve_problem_054(file_name))
