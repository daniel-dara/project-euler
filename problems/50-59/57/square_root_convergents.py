from typing import Tuple

expansions = {0: (0, 1)}  # Seed the base expansion.


def solve() -> int:
    """Find the number of fractions containing a numerator with more digits than the denominator in the first
    one-thousand expansions of the given expression.
    """
    return sum(len(str(expand(x)[0])) > len(str(expand(x)[1])) for x in range(1000))


def expand(x: int) -> Tuple[int, int]:
    # Pull the expanded fraction for this iteration from cache.
    expanded_numerator, expanded_denominator = expansions[x]

    # Calculate "1 / (2 + expanded_fraction)
    numerator = expanded_denominator
    denominator = (2 * expanded_denominator) + expanded_numerator

    # Cache the new expanded fraction for the next iteration.
    expansions[x + 1] = numerator, denominator

    # Calculate "1 + new_fraction"
    return numerator + denominator, denominator
