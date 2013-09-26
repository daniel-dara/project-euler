#include <stdio.h>

int main()
{
	int a = 0, b = 0, c = 0, m = 0, n;

	/*	Euclid's Formula (m^2 - n^2)^2 + (2mn)^2 = (m^2 + n^2)^2
	    So: a = m^2 - n^2, b = 2mn, c = m^2 + n^2
	    So given an m, we can find an n such that a + b + c = 1000 and
	    produces a pythagorean triplet. */

	// 'a' must be greater than 0 since the problem
	// specified that the triplet only contains natural numbers
	while (a + b + c != 1000 || a < 0)
	{
		// increment m
		m++;

		// calcaulte n from m
		n = (1000 - 2 * m * m) / (2 * m);

		// calculate a, b, and c
		a = m * m - n * n;
		b = 2 * m * n;
		c = m * m + n * n;
	}

	printf("%d\n", a * b * c);

	return 0;
}
