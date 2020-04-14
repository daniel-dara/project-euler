from itertools import count
from math import sqrt

primes = [2]  # Seed the even prime so the solve() loop can iterate over just odds.


def solve() -> bool:
	"""Find the smallest odd composite that cannot be written as the sum of a prime and twice a square."""
	return next(number for number in count(3, 2) if not is_prime(number) and not is_goldbach(number))


def is_prime(number: int) -> bool:
	for prime in primes:
		# Optimization: If no prime factor is found less than the root, then there are no prime factors.
		if prime > sqrt(number):
			break

		if number / prime % 1 == 0:
			return False

	primes.append(number)
	return True


def is_goldbach(odd_composite: int) -> bool:
	for prime in primes:
		if sqrt((odd_composite - prime) / 2) % 1 == 0:
			return True

	return False

