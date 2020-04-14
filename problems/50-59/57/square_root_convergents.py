from typing import Tuple

expansions = {0: (0, 1)}  # Seed the base expansion.


def solve() -> int:
    """Find the number of fractions containing a numerator with more digits than the denominator in the first
    one-thousand expansions of the given expression.
    """
    return sum(len(str(expand(x)[0])) > len(str(expand(x)[1])) for x in range(1000))


def expand(x: int) -> Tuple[int, int]:
    previous_numerator, previous_denominator = expansions[x]

    numerator = previous_denominator
    denominator = (2 * previous_denominator) + previous_numerator

    expansions[x + 1] = numerator, denominator
    return numerator + denominator, denominator
