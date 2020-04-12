from typing import List, Tuple

from utils.primesieve import PrimeSieve


def solve() -> int:
    """Find the 12-digit number formed by concatenating the three terms described in the problem statement."""
    given_sequence = (1487, 4817, 8147)
    sequences = find_all_sequences()
    sequences.remove(given_sequence)

    return int(''.join(map(str, sequences[0])))


def find_all_sequences() -> List[Tuple[int, int, int]]:
    """Find all sequences of three numbers which are each equal distance apart, 4-digit primes, and permutations
    of each other.
    """
    primes = list(filter(lambda x: len(str(x)) == 4, PrimeSieve(9999)))
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
