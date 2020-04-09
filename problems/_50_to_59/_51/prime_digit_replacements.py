from collections import defaultdict
from more_itertools import powerset
from typing import Dict, List

from utils.primesieve import PrimeSieve
from utils.string import indices_at, unique_chars, replace_char_at_indices


def solve(family_size: int) -> int:
    """Find the smallest prime which is part of a family of the given size."""
    # Map families to their family members
    # A family is represented as a string number with specific digits replaced by asterisks.
    # Example entry: {'56**3': [56003, 56113, 56333, ...]}
    families: Dict[str, List[int]] = defaultdict(lambda: [])

    # Add each prime to all families it is a member of, repeat until a family reaches the target size.
    for prime in PrimeSieve():
        for family in get_families(prime):
            families[family].append(prime)

            if len(families[family]) == family_size:
                return min(families[family])


def get_families(number: int) -> str:
    """Generator function that yields each family that the given number belongs to."""

    for digit in unique_chars(str(number)):
        digit_indices = indices_at(str(number), digit)

        # Each possible subset of same digits must be replaced since the problem statement does not require that all
        # digits be replaced at once.
        for indices_subset in powerset(digit_indices):
            if indices_subset != ():  # At least one digit must be replaced to be considered a family.
                yield replace_char_at_indices(str(number), '*', indices_subset)
