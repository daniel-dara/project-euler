

def solve() -> int:
    """Find the maximum digital sum of a^b for a, b < 100"""
    return max(sum(map(int, str(a ** b))) for a in range(100) for b in range(100))
