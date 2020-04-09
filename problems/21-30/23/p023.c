#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// array to hold abundant numbers
int abundantSums[28124];

inline int isAbundant(int num)
{
	int i, sum = 1;
	double root = sqrt(num);

	// loop over all possible divisors less than the root
	for (i = 2; i <= root && sum <= num; i++)
	{
		// if 'i' is a proper divisor
		if (num % i == 0)
		{
			// add it to 'sum'
			sum += i;

			// check that 'i' isn't the square root
			if (i != root)
			{
				// add the symmetric divisor of 'i' to 'sum' as well
				sum += num / i;
			}
		}
	}

	return sum > num;
}

int main()
{
	int i, j, index = 0, sum, total = 0;

	// calculate the necessary abundant numbers
	for (i = 12; i <= 28123; i++)
	{
		if (isAbundant(i))
		{
			abundantSums[index++] = i;
		}
	}

	int* isSumOfAbundants = calloc(28124, sizeof(int));

	// loop over all possible pairs of abundant numbers
	for (i = 0; i < index; i++)
	{
		for (j = 0; j < index; j++)
		{
			// if their sum is under 28124
			if ((sum = abundantSums[i] + abundantSums[j]) < 28124)
			{
				// flag the sum
				isSumOfAbundants[sum] = 1;
			}
		}
	}

	// sum all of the numbers that aren't the sum
	// of two abundant numbers
	for (i = 0; i < 28124; i++)
	{
		if (!isSumOfAbundants[i])
		{
			total += i;
		}
	}

	printf("%d\n", total);

	return 0;
}
