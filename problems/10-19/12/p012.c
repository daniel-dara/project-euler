#include <stdio.h>
#include <math.h>

int divisors(int num)
{
	int i, total = 0;
	double root = sqrt(num); // save time re-calculating in loop

	for (i = 1; i < (int) root + 1; i++)
	{
		if (num % i == 0)
		{
			// all divisors are symmetric unless it is the square root
			total += ((double) i != root ? 2 : 1);
		}
	}

	return total;
}

int main()
{
	int num = 1, i = 1;

	while (divisors(num) <= 500)
	{
		i++;      // i represents the term
		num += i; // and we add it to the i-1 term to get the ith term
	}

	printf("%d\n", num);

	return 0;
}
