#include <stdio.h>
#include <math.h>

/* A quick and easy isPrime function. It could
   be upgraded to populate a table to avoid repeat
	checks but the problem does not require such
   heurestics. */

int isPrime(int n)
{
	if (n < 2)
		return 0;

	int root = sqrt(n), i;

	for (i = 2; i <= root; i++)
	{
		if (n % i == 0)
			return 0;
	}

	return 1;
}


/* Count the number of primes produced by these coefficients
   in the formula n^2 + an + b. */

int primeCount(int a, int b)
{
	int n = 0;

	while (isPrime(n * n + a * n +  b))
	{
		n++;
	}

	return n;
}

int main()
{
	int a, b, max = 0, temp, bestA, bestB;

	for (a = -1000; a < 1000; a++)
	{
		for (b = -1000; b < 1000; b++)
		{
			if ((temp = primeCount(a, b)) > max)
			{
				max = temp;
				bestA = a;
				bestB = b;
			}
		}
	}

	printf("%d\n", bestA * bestB);

	return 0;
}
