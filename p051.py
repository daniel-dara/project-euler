from collections import defaultdict
from typing import Dict, List
from more_itertools import powerset
from utils.primesieve import PrimeSieve
from utils.string import indices_at, unique_chars, replace_char_at_indices


def solve_problem_051(target_family_count: int) -> int:
    # A map of family ids to family members
    families: Dict[str, List[int]] = defaultdict(lambda: [])

    for prime in PrimeSieve():
        for family in get_family_ids(prime):
            families[family].append(prime)

            if len(families[family]) == target_family_count:
                return min(families[family])


def get_family_ids(number: int) -> str:
    for char in unique_chars(str(number)):
        char_indices = indices_at(str(number), char)

        for indices in powerset(char_indices):
            if indices != ():
                family_id = replace_char_at_indices(str(number), '*', indices)
                yield family_id
