from utils.primesieve import PrimeSieve


def solve(max_number: int) -> int:
    prime_list = list(PrimeSieve(max_number))
    prime_set = set(prime_list)  # Minor optimization for constant time lookups.

    longest_window = []
    start, end = 0, 1
    window = prime_list[start:end]

    # Once the current window shrinks below the longest one found, it is no longer possible to find another sum of the
    # same length that is less than max_number.
    while len(window) >= len(longest_window):
        if sum(prime_list[start:end + 1]) >= max_number:
            # If extending the end of the window would put the sum over the max_number, move the start first to
            # ensure all possible consecutive sums are tested.
            start += 1
        else:
            end += 1

        window = prime_list[start:end]

        if len(window) > len(longest_window) and sum(window) in prime_set:
            longest_window = window

    return sum(longest_window)
