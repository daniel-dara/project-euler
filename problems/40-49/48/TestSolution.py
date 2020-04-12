from unittest import TestCase

from unittest_data_provider import data_provider

from .self_powers import solve


class TestSolution(TestCase):
    @data_provider(lambda: (
        (10, '0405071317'),
        (1_000, '9110846700'),
    ))
    def test_solve(self, series_end: int, expected_last_10: int):
        self.assertEqual(expected_last_10, solve(series_end))
