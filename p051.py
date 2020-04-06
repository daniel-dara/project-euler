from collections import defaultdict
from typing import Dict, List
from more_itertools import powerset
from utils.primesieve import PrimeSieve
from utils.string import indices_at, unique_chars, replace_char_at_indices


def solve_problem_051(target_family_count: int) -> int:
    # map family ids to family members where a family id is a number with specific digits replaced by asterisks
    # ex: {'56**3': [56003, 56113, 56333, ...]}
    families: Dict[str, List[int]] = defaultdict(lambda: [])

    # add each prime to all families it is a member of, repeat until a family reaches the target count
    for prime in PrimeSieve():
        for family_id in get_family_ids(prime):
            families[family_id].append(prime)

            if len(families[family_id]) == target_family_count:
                return min(families[family_id])


def get_family_ids(number: int) -> str:
    # chars are digits
    for char in unique_chars(str(number)):
        char_indices = indices_at(str(number), char)

        # each possible subset of same digits must be replaced since the problem statement does not require that all
        # digits be replaced at once
        for indices_subset in powerset(char_indices):
            if indices_subset != ():  # skip the empty subset
                family_id = replace_char_at_indices(str(number), '*', indices_subset)
                yield family_id
