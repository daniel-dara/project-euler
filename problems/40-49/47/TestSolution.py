from unittest import TestCase

from unittest_data_provider import data_provider

from .distinct_primes_factors import solve


class TestSolution(TestCase):
    @data_provider(lambda: (
        (2, 14),
        (3, 644),
        (4, 134043),
    ))
    def test_solve(self, x: int, expected_first_number: int):
        self.assertEqual(expected_first_number, solve(x))
