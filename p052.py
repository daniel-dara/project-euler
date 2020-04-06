from itertools import count


def solve_problem_052(max_multiplier: int) -> int:
    # iterate to infinity
    for number in count(1):
        # calculate the products that must match
        products = [multiplier * number for multiplier in range(2, max_multiplier + 1)]

        # determine if the digits of the products match each other
        if all(same_digits(number, product) for product in products):
            return number


def same_digits(a: int, b: int) -> bool:
    return sorted(str(a)) == sorted(str(b))
