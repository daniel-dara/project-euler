from unittest import TestCase
from unittest_data_provider import data_provider
import pathlib

from .poker_hands import solve


class TestSolution(TestCase):
    PATH = str(pathlib.Path(__file__).parent.absolute())

    @data_provider(lambda: (
        (TestSolution.PATH + '/input/example.txt', 3),
        (TestSolution.PATH + '/input/problem.txt', 376),
    ))
    def test_solve(self, file_name: str, expected: int):
        self.assertEqual(expected, solve(file_name))



