from unittest import TestCase

from .xor_decryption import solve


class TestSolution(TestCase):
    def test_solve(self):
        self.assertEqual(129448, solve())
