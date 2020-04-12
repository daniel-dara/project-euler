from typing import List, Collection


def unique_chars(string: str) -> str:
    """Returns a string of unique characters from the given string. Order is preserved based on first occurrence."""
    return ''.join({char: None for char in string}.keys())


def indices_at(haystack: str, needle: str) -> List[int]:
    """Returns a list of all indices where needle is found in the haystack. Needles can overlap."""
    # Add one to the range to properly count empty needles since one is between each character and at both ends.
    return [index for index in range(len(haystack) + 1) if haystack[index:index + len(needle)] == needle]


def replace_char_at_indices(subject: str, replace: str, indices: Collection[int]) -> str:
    """Returns a string with all characters at the given indices replaced with the replacement value. Indices
    reference the original string and are not affected by replacement length. Indices that do not contain a character
    are ignored. So for (i < 0 or i >= len()), i is ignored.
    """
    return ''.join((subject[index] if index not in indices else replace) for index in range(len(subject)))
