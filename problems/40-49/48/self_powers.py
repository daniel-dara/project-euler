
def solve(series_end: int) -> str:
    """Find the last ten digits of the series a ^ a from 1 to the given end."""
    return str(sum(i ** i for i in range(1, series_end + 1)))[-10:]
