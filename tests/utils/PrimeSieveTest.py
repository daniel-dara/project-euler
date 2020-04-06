import unittest
from utils.primesieve import PrimeSieve
from unittest_data_provider import data_provider


class PrimeSieveTest(unittest.TestCase):
    @data_provider(lambda: (
        (-1,),
        (0,),
        (1,),
    ))
    def test_invalid_value(self, invalid_num: int):
        with self.assertRaises(ValueError):
            PrimeSieve(invalid_num)

    def test_base_value(self):
        self.assertEqual([2], list(PrimeSieve(2)))

    def test_second_value(self):
        self.assertEqual([2, 3], list(PrimeSieve(3)))

    def test_several_values_end_on_prime(self):
        self.assertEqual([2, 3, 5, 7, 11], list(PrimeSieve(11)))

    def test_several_values_end_on_non_prime(self):
        self.assertEqual([2, 3, 5, 7, 11], list(PrimeSieve(12)))

    def test_primes_under_100(self):
        primes_under_100 = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
                            43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

        self.assertEqual(primes_under_100, list(PrimeSieve(100)))

    def test_no_limit_first_8_primes(self):
        prime_sieve = PrimeSieve()
        primes = [next(prime_sieve) for _ in range(8)]

        self.assertEqual([2, 3, 5, 7, 11, 13, 17, 19], primes)
