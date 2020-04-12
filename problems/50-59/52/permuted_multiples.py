from itertools import count


def solve(max_multiplier: int) -> int:
    """Find the smallest positive integer such that each product up to the given multiplier contains the same digits."""
    for number in count(1):
        products = [multiplier * number for multiplier in range(2, max_multiplier + 1)]

        if all(contain_same_digits(number, product) for product in products):
            return number


def contain_same_digits(a: int, b: int) -> bool:
    return sorted(str(a)) == sorted(str(b))
