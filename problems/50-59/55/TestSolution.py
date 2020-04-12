from unittest import TestCase

from unittest_data_provider import data_provider

from .lychrel_numbers import solve, is_lychrel


class TestSolution(TestCase):
    def test_solve(self):
        self.assertEqual(249, solve())

    @data_provider(lambda: (
        (47, False),
        (349, False),
        (10677, True),  # Lychrel based on problem statement (over fifty iterations).
    ))
    def test_is_lychrel(self, number: int, expected: bool):
        self.assertEqual(expected, is_lychrel(number))
