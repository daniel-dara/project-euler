from typing import Tuple, List, Dict
from more_itertools import powerset
from utils.primesieve import PrimeSieve


def unique_chars(string: str) -> str:
    return ''.join(set(string))


def find_chars(haystack: str, needle: str) -> List[int]:
    if len(needle) != 1:
        raise ValueError('needle should be exactly one character')

    return [index for index, char in enumerate(haystack) if char == needle]


def remove_indices(string: str, indices: Tuple[int]) -> str:
    return str([string[index] for index in range(len(string)) if index not in indices])


def get_digit_positions(number: int) -> Tuple:
    for char in unique_chars(str(number)):
        char_indices = find_chars(str(number), char)

        for index_subset in powerset(char_indices):
            if index_subset != ():
                stripped_number = remove_indices(str(number), index_subset)
                yield stripped_number, index_subset


class PrimeFamily:
    def __init__(self, lowest_prime: int):
        self.lowest_prime = lowest_prime
        self.family_count = 1


def solve_p051(target_prime_family_count: int) -> int:
    # A map of (digit_positions) to PrimeFamily
    family_counts: Dict[Tuple[List[int]], PrimeFamily] = {}

    for prime in PrimeSieve():
        for digit_positions in get_digit_positions(prime):
            if digit_positions in family_counts:
                family_counts[digit_positions].family_count += 1
            else:
                family_counts[digit_positions] = PrimeFamily(prime)

            if family_counts[digit_positions].family_count == target_prime_family_count:
                return family_counts[digit_positions].lowest_prime
