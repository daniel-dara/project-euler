from typing import List, Tuple

from utils.primesieve import PrimeSieve


def solve() -> int:
    given_sequence = (1487, 4817, 8147)
    sequences = find_all_sequences()
    sequences.remove(given_sequence)

    return int(''.join(map(str, sequences[0])))


def find_all_sequences() -> List[Tuple[int, int, int]]:
    # Retrieve all 4 digit primes.
    primes = list(filter(lambda x: x > 999, PrimeSieve(9999)))
    sequences = []

    for first_index in range(len(primes)):
        for second_index in range(first_index + 1, len(primes)):
            first_prime = primes[first_index]
            second_prime = primes[second_index]
            third_number = second_prime + (second_prime - first_prime)

            if are_permutations([first_prime, second_prime, third_number]) and third_number in primes:
                sequences.append((first_prime, second_prime, third_number))

    return sequences


def are_permutations(numbers: List[int]) -> bool:
    return len(set(tuple(sorted(str(number))) for number in numbers)) == 1
