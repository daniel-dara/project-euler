#include <stdio.h>
#include <math.h>

int main()
{
	long int num = 600851475143, i;

	// dynamic loop
	for (i = 2; i < num; i++)
	{
		while (num % i == 0)
		{
			// factor out all primes and update num to be what's left
			num /= i;
		}
	}

	// by the end of the loop, num will be the largest prime factor
	printf("%ld\n", num);

	return 0;
}
