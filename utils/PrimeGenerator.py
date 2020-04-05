import math


class PrimeGenerator(object):
    def __init__(self, max_number: int = None):
        if max_number < 2:
            raise ValueError('max_number must be greater than or equal to 2.')

        self.primes = [2]
        self.last_prime = None

        self.max_number = max_number
        self.current_number = 2

    def __iter__(self):
        return self

    def __next__(self):
        # The first prime (2) is special cased so that the loop to find subsequent primes can increment by 2.
        # Incrementing by 2 skips even numbers for a slight optimization.
        if self.current_number == 2:
            self.last_prime = 2
            self.current_number = 3
        else:
            while not self.__has_found_next_prime():
                if self.__has_reached_max():
                    raise StopIteration

                if self.__is_prime(self.current_number):
                    self.primes.append(self.current_number)

                self.current_number += 2

            self.last_prime = self.primes[-1]

        return self.last_prime

    def __has_found_next_prime(self):
        return self.last_prime != self.primes[-1]

    def __has_reached_max(self):
        return self.max_number is not None and self.current_number > self.max_number

    def __is_prime(self, number: int):
        root = math.sqrt(number)

        for prime in self.primes:
            if prime > root:
                break

            if number % prime == 0:
                return False

        return True

    class InvalidArgument(Exception):
        pass
