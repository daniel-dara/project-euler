import math


def solve() -> int:
    """Find the side length of the square spiral with a ratio of primes along both diagonals falling below 10%"""
    i = 1
    length = 1
    diagonal_prime_count = 0

    # Diagonal count = ((4 * length / 2) - 1) = (2 * length - 1)
    # Explanation: (number_of_corners * length / growth_rate_of_length) - center_of_spiral
    while length == 1 or diagonal_prime_count / (2 * length - 1) >= 0.1:
        length += 2

        for corner in range(4):
            i += length - 1

            # Optimization: Skip the prime check on the bottom right diagonal since it is always an odd square.
            if corner < 3 and is_prime(i):
                diagonal_prime_count += 1

    return length


def is_prime(number: int) -> bool:
    """An optimized trial division check for primality that only works on odd input and the number 2."""
    if number <= 3:
        return number != 1

    for i in range(3, math.floor(math.sqrt(number) + 1), 2):
        if number % i == 0:
            return False

    return True
