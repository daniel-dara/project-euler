import itertools

import sympy

primes = [prime for prime in sympy.primerange(2, 1_000)]

print(len(primes))

# TODO Instead of brute forcing all 5 primes, precompute all pairs of primes and
# compare matches to find the subset of 5 interchangeable primes.
for subset in itertools.combinations(primes, 5):
    all_prime = True

    for a, b in itertools.permutations(subset, 2):
        if not sympy.isprime(int(str(a) + str(b))):
            all_prime = False
            break

    if all_prime:
        print(subset, sum(subset))
        exit()

print('done')
