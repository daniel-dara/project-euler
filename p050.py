from math import sqrt

primes = [2]         # for determining primality of a new number quickly, primes must be kept in order
prime_set = set([2]) # for determining primality of a known number in constant time, order doesn't matter

def calcPrimality(num):
	root = sqrt(num)

	for prime in primes:
		if prime > root:
			break
		elif num % prime == 0:
			return False

	primes.append(num)
	prime_set.add(num)
	return True

i = 3
max_num = 1000000

while primes[-1] < max_num:
	calcPrimality(i)
	i += 2

max_len = 0
max_prime = 0
i = 0

while max_len == 0 or length >= max_len:
	length = 1
	total  = primes[i]

	j = i + 1
	while total + primes[j] < max_num:
		length += 1
		total  += primes[j]

		if total in primes and length > max_len:
			max_len   = length
			max_prime = total

		j += 1

	i += 1

print(max_prime)
