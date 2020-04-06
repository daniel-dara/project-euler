import unittest
from unittest_data_provider import data_provider
from p051 import solve_problem_051


class Problem051Test(unittest.TestCase):
    @data_provider(lambda: (
        (6, 13),
        (7, 56003),
        (8, 121313),
    ))
    def test_solve(self, prime_family_count: int, lowest_prime: int):
        self.assertEqual(lowest_prime, solve_problem_051(prime_family_count))
