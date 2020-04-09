#include <stdio.h>
#include <math.h>

int main()
{
	int sumOfSquares = 0, i;

	// Sum the squares of the sequence 1 to 100
	for (i = 1; i <= 100; i++)
	{
		sumOfSquares += i * i;
	}

	// Calculate the sum of the sequence 1 to 100 and square it
	int sumSquared = pow(100 * (100 + 1) / 2, 2);

	// Take absolute value of difference between the two
	printf("%d\n", (int) fabs(sumOfSquares - sumSquared));

	return 0;
}
