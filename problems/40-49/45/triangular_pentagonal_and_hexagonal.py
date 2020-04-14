from collections import defaultdict
from itertools import count


def solve(answer_greater_than: int) -> int:
    """Find a number that is triangular, pentagonal, and hexagonal and is greater than the given number."""
    occurrences = defaultdict(lambda: 0)

    for n in count():
        for number in (triangular(n), pentagonal(n), hexagonal(n)):
            occurrences[number] += 1

            if occurrences[number] == 3 and number > answer_greater_than:
                return number


def triangular(n: int) -> int:
    return n * (n + 1) // 2


def pentagonal(n: int) -> int:
    return n * (3*n - 1) // 2


def hexagonal(n: int) -> int:
    return n * (2*n - 1)
