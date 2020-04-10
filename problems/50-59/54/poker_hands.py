from __future__ import annotations

from collections import Counter
from enum import Enum
from typing import List, Tuple


def solve(file_name: str) -> int:
    """Count the number of Poker hands that player 1 wins from the given input file."""
    player1_win_count = 0

    with open(file_name) as file:
        for row in file:
            cards = [Card(rank, suit) for rank, suit in row.strip().split(' ')]
            hand1, hand2 = Hand(cards[:5]), Hand(cards[5:])

            if hand1.beats(hand2):
                player1_win_count += 1

    return player1_win_count


class Card:
    def __init__(self, rank: str, suit: str):
        self.rank = '23456789TJQKA'.index(rank) + 2
        self.suit = suit

    def tuple(self) -> Tuple[int, str]:
        return self.rank, self.suit


class Hand:
    def __init__(self, cards: List[Card]):
        self._cards = sorted(cards, key=lambda card: card.tuple(), reverse=True)

        self._is_same_suit = all(self._cards[0].suit == card.suit for card in self._cards)
        self._is_straight = all(high.rank == low.rank + 1 for high, low in zip(self._cards[:4], self._cards[1:]))

        self._rank_counts = Counter([card.rank for card in self._cards]).most_common()
        self._type = self._get_type()

    def beats(self, other: Hand) -> bool:
        # Check if one hand is outright better than the other.
        if self._type != other._type:
            return self._type.value > other._type.value

        # If the hands tie then compare individual card ranks.
        for a, b in zip(self._rank_counts, other._rank_counts):
            if a != b:
                return a > b

        raise Exception('Problem statement does not allow for ties')

    def _get_type(self) -> Type:
        if self._is_same_suit and self._is_straight:
            if self._cards[0].rank == 13:
                return self.Type.ROYAL_FLUSH
            else:
                return self.Type.STRAIGHT_FLUSH
        elif self._rank_counts[0][1] == 4:
            return self.Type.FOUR_OF_A_KIND
        elif self._rank_counts[0][1] == 3:
            if self._rank_counts[1][1] == 2:
                return self.Type.FULL_HOUSE
            else:
                return self.Type.THREE_OF_A_KIND
        elif self._is_same_suit:
            return self.Type.FLUSH
        elif self._is_straight:
            return self.Type.STRAIGHT
        elif self._rank_counts[0][1] == 2:
            if self._rank_counts[1][1] == 2:
                return self.Type.TWO_PAIRS
            else:
                return self.Type.ONE_PAIR
        else:
            return self.Type.HIGH_CARD

    class Type(Enum):
        HIGH_CARD = 1
        ONE_PAIR = 2
        TWO_PAIRS = 3
        THREE_OF_A_KIND = 4
        STRAIGHT = 5
        FLUSH = 6
        FULL_HOUSE = 7
        FOUR_OF_A_KIND = 8
        STRAIGHT_FLUSH = 9
        ROYAL_FLUSH = 10
