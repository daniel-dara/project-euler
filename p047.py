import math

def isPrime(num):
	for prime in primes:
		if num % prime == 0:
			return False

	primes.append(num)
	return True

def hasDistinctPrimeFactors(num):
	factors = 0

	for prime in primes:
		if num % prime == 0:
			factors += 1

			if factors > NUM:
				return False

			while num % prime == 0:
				num /= prime

				if num == 0:
					return factors == NUM

	return factors == NUM

i = 2
primes = []
NUM = 4
count = 0
first = 0

while count < NUM:
	if not isPrime(i) and hasDistinctPrimeFactors(i):
		if count == 0:
			first = i

		count += 1
	else:
		count = 0

	i += 1

print(first)
