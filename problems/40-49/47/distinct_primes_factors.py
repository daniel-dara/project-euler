from itertools import count
from typing import Set, Generator, List

from utils.primesieve import PrimeSieve

prime_cache: List[int] = []
prime_sieve = PrimeSieve()
factors_cache = {0: set(), 1: set()}  # Cache is seeded to handle base cases.


def solve(x: int) -> int:
    """Find x consecutive integers that have x distinct prime factors each."""
    return next(i for i in count() if all(len(distinct_prime_factors(j)) == x for j in range(i, i + x)))


def distinct_prime_factors(number: int) -> Set[int]:
    """Find the distinct prime factors of the given numbers.
    Uses a cache for faster factorization of previously processed numbers.
    """
    remainder = number
    prime_factors = set()

    for prime in prime_generator():
        if remainder in factors_cache:
            factors_cache[number] = factors_cache[remainder].union(prime_factors)
            return factors_cache[number]

        while remainder % prime == 0:
            prime_factors.add(prime)
            remainder /= prime


def prime_generator() -> Generator[int, None, None]:
    """An infinite prime generator with a cache so repeated generation is less expensive."""
    for prime in prime_cache:
        yield prime

    prime_cache.append(next(prime_sieve))
    yield prime_cache[-1]
