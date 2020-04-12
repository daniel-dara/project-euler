import math


class PrimeSieve:
    def __init__(self, max_number: int = None):
        if max_number is not None and max_number < 2:
            raise ValueError('max_number must be greater than or equal to 2.')

        self.primes = [2]
        self.last_prime = None

        self.max_number = max_number
        self.current_number = 2

    def __iter__(self):
        return self

    def __next__(self) -> int:
        # Optimization: The first prime (2) is special cased so that the loop for finding primes can start at 3 and
        # increment by 2 (as opposed to a slower, conventional loop incrementing by 1).
        if self.current_number == 2:
            self.last_prime = 2
            self.current_number = 3
        else:
            while not self._has_found_next_prime():
                if self._has_reached_max():
                    raise StopIteration

                if self._is_prime(self.current_number):
                    self.primes.append(self.current_number)

                self.current_number += 2

            self.last_prime = self.primes[-1]

        return self.last_prime

    def _has_found_next_prime(self) -> bool:
        return self.last_prime != self.primes[-1]

    def _has_reached_max(self) -> bool:
        return self.max_number is not None and self.current_number > self.max_number

    def _is_prime(self, number: int) -> bool:
        # Optimization: Convert root to an integer for faster comparisons against 'prime'.
        root = math.ceil(math.sqrt(number))

        for prime in self.primes:
            if prime > root:
                break

            if number % prime == 0:
                return False

        return True

    class InvalidArgument(Exception):
        pass
