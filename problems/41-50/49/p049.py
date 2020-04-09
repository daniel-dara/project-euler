import math
from itertools import permutations

primes = []

def calcPrimality(num):
	for prime in primes:
		if num % prime == 0:
			return False

	primes.append(num)
	return True

for i in range(2, 10000):
	calcPrimality(i)

def containsSequence(forms):
	for i in range(len(forms) - 1):

		if forms[i] > 1000:
			for j in range(i + 1, len(forms)):
				diff = forms[j] - forms[i]

				if forms[j] + diff in forms:
					return (forms[i], forms[j], forms[j] + diff)

i = 0
while i < len(primes):
	if primes[i] > 1000:
		forms = []

		for permutation in set(permutations(str(primes[i]))):
			permutation = int(''.join(permutation))

			if permutation in primes:
				del primes[primes.index(permutation)]
				forms.append(permutation)

		forms.sort()

		if len(forms) >= 3:
			seq = containsSequence(forms)

			if seq:
				print(''.join(map(str, seq)))

	i += 1
