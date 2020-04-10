import math


def solve() -> int:
    return sum(binomial_coefficient(n, r) > 1_000_000 for n in range(1, 100 + 1) for r in range(1, n + 1))


def binomial_coefficient(n: int, r: int) -> int:
    return int(math.factorial(n) / (math.factorial(r) * math.factorial(n - r)))