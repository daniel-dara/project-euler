#include <stdio.h>
#include <math.h>

int solutions(int p)
{
	int a, b, total = 0;

	// brute force search over a and b
	for (a = 1; a < p; a++)
	{
		// start b at a to avoid double counting and stop if a + b alone is > p
		for (b = a; b < p && a + b + 1 < p; b++)
		{
			// calculate c and increment solution total if sum == p
			if (a + b + sqrt(a * a + b * b) == p)
			{
				total++;
			}
		}
	}

	return total;
}

int main()
{
	int p, maxSolutions = 0, bestP = 0, sol;

	// Lowest possible p is 12 (3-4-5 triangle)
	for (p = 12; p <= 1000; p++)
	{
		if ((sol = solutions(p)) > maxSolutions)
		{
			maxSolutions = sol;
			bestP = p;
		}
	}

	printf("%d\n", bestP);

	return 0;
}
