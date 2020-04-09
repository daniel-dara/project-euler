from itertools import count


def solve(max_multiplier: int) -> int:
    """Find the smallest positive integer such that each product up to the given multiplier contains the same digits."""
    # Iterate to infinity.
    for number in count(1):
        # Calculate the products that must match.
        products = [multiplier * number for multiplier in range(2, max_multiplier + 1)]

        # Determine if the digits of the products match each other.
        if all(contain_same_digits(number, product) for product in products):
            return number


def contain_same_digits(a: int, b: int) -> bool:
    return sorted(str(a)) == sorted(str(b))
