from itertools import product, cycle
from pathlib import Path

PATH = str(Path(__file__).parent.absolute())
CIPHER_CHARS = list(map(ord, 'abcdefghijklmnopqrstuvwxyz'))


def solve() -> int:
    """Find the sum of ASCII values in the decrypted problem input."""
    with open(PATH + '/input/cipher.txt') as file:
        encrypted_values = list(map(int, file.readlines()[0].split(',')))

    decrypted_possibilities = [
        [a ^ b for a, b in zip(encrypted_values, cycle(key))]
        for key in product(CIPHER_CHARS, CIPHER_CHARS, CIPHER_CHARS)
    ]

    return sum(max(decrypted_possibilities, key=lambda values: values.count(ord(' '))))
