from unittest import TestCase

from unittest_data_provider import data_provider

from .consecutive_prime_sum import solve


class TestSolution(TestCase):
    @data_provider(lambda: (
        (100, 41),
        (1_000, 953),
        (1_000_000, 997651),
    ))
    def test_solve(self, max_number: int, expected_prime: int):
        self.assertEqual(expected_prime, solve(max_number))
