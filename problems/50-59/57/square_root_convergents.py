from itertools import repeat
from typing import Tuple

expansions = {}


def solve() -> int:
    """Find the number of fractions containing a numerator with more digits than the denominator in the first
    one-thousand expansions of the given expression.
    """
    return sum(len(str(expand(n)[0])) > len(str(expand(n)[1])) for n in range(1000))


def expand(n: int) -> Tuple[int, int]:
    if n == 0:
        # Handle base case.
        numerator = 1
        denominator = 2
    else:
        # Pull the expanded fraction for the previous iteration from cache.
        previous_numerator, previous_denominator = expansions[n - 1]

        # Calculate 1 / (2 + previous fraction)
        numerator = previous_denominator
        denominator = (2 * previous_denominator) + previous_numerator

    # Cache the expanded fraction for this iteration
    expansions[n] = numerator, denominator

    # Calculate 1 + fraction
    return numerator + denominator, denominator
