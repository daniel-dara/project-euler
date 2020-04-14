from unittest import TestCase

from unittest_data_provider import data_provider

from .triangular_pentagonal_and_hexagonal import solve


class TestSolution(TestCase):
    @data_provider(lambda: (
        (-1, 0),
        (0, 1),
        (2, 40755),
        (40755, 1533776805),
    ))
    def test_solve(self, answer_greater_than: int, expected_number: int):
        self.assertEqual(expected_number, solve(answer_greater_than))
