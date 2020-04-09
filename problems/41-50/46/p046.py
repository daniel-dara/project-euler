import math

i = 2
primes = []

def isPrime(num):
	for prime in primes:
		if num / prime % 1 == 0:
			return False

	primes.append(num)
	return True

def isGoldbach(num):
	for prime in primes:
		x = (num - prime) / 2

		if x % 1 == 0 and math.sqrt(x) % 1 == 0:
			return True

	return False

while isPrime(i) or i % 2 == 0 or isGoldbach(i):
	i += 1

print(i)
