# Combinatoric selections
## [Problem 53](https://projecteuler.net/problem=53)

There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, <img src="https://latex.codecogs.com/gif.latex?\binom 5 3 = 10" />.

In general, <img src="https://latex.codecogs.com/gif.latex?\binom n r = \dfrac{n!}{r!(n-r)!}" />, where r ≤ n, n != n × (n − 1) × ... × 3 × 2 × 1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: <img src="https://latex.codecogs.com/gif.latex?\binom {23} {10} = 1144066" />.

How many, not necessarily distinct, values of <img src="https://latex.codecogs.com/gif.latex?\binom n r" /> for 1 ≤ n ≤ 100, are greater than one-million?
