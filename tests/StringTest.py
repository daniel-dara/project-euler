import unittest
from typing import List

from unittest_data_provider import data_provider
from utils.string import unique_chars, indices_at, replace_char_at_indices


class StringTest(unittest.TestCase):
    @data_provider(lambda: (
        ('', ''),
        ('a', 'a'),
        ('aa', 'a'),
        ('abc', 'abc'),
        ('fabbbacddf', 'fabcd'),
    ))
    def test_unique_chars(self, _input: str, expected: str):
        self.assertEqual(expected, unique_chars(_input))

    @data_provider(lambda: (
        # empty needles
        ('', '', [0]),
        ('a', '', [0, 1]),
        ('abc', '', [0, 1, 2, 3]),
        # char needles
        ('', 'a', []),
        ('a', 'a', [0]),
        ('aaa', 'a', [0, 1, 2]),
        ('babbbab', 'a', [1, 5]),
        # string needles
        ('', 'abc', []),
        ('abcdef', 'abcd', [0]),
        ('aabcdeff', 'abcd', [1]),
        ('abcdabcdabcd', 'abc', [0, 4, 8]),
        ('abccccabc', 'abc', [0, 6]),
        ('abcdeabcde', 'abcde', [0, 5]),
        # overlapping needles
        ('aaa', 'aa', [0, 1]),
        ('aaaaa', 'aa', [0, 1, 2, 3]),
    ))
    def test_indices_at(self, haystack: str, needle: str, expected: List[int]):
        self.assertEqual(expected, indices_at(haystack, needle))

    @data_provider(lambda: (
        # empties
        ('', '', [], ''),
        ('', '', [0], ''),
        ('', 'a', [0], ''),
        ('', 'a', [0, 1], ''),
        # char subject
        ('a', 'b', [], 'a'),
        ('a', 'b', [0], 'b'),
        ('a', 'b', [1], 'a'),
        ('a', 'b', [0, 1], 'b'),
        ('a', 'bc', [0], 'bc'),
        # str subject
        ('abcdef', 'b', [2], 'abbdef'),
        ('abcdef', '', [2], 'abdef'),
        ('abcdef', 'b', [2, 4, 5], 'abbdbb'),
        ('abcdef', '', [2, 4, 5], 'abd'),
        ('abcdef', '54', [-1, 1, 3, 100], 'a54c54ef'),
    ))
    def test_replace_char_at_indices(self, subject: str, replace: str, indices: List[int], expected: str):
        self.assertEqual(expected, replace_char_at_indices(subject, replace, indices))
