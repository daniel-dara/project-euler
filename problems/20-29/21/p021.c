#include <stdio.h>

int main()
{
	int sums[10001], i, j, amicableSum = 0;

	for (i = 2; i <= 10000; i++)
	{
		// initialize sum to 1 since it is a proper divisor of every number
		sums[i] = 1;

		// calculate the sum of proper divisors
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				sums[i] += j;
			}
		}

		// check for amicable pair below the current number
		// this prevents double counting and having to
		// loop over the sums again to get the grand total
		if (sums[i] < i && sums[sums[i]] == i)
		{
			amicableSum += i + sums[i];
		}
	}

	printf("%d\n", amicableSum);

	return 0;
}
