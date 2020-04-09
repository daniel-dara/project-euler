#include <stdio.h>
#include <math.h>

/* It is a fact that there will be less than 1,000,000
   primes less than 2,000,000 since half of the numbers
   between 1 and 2,000,000 are even and thus not prime. */
int primes[1000000] = {2};

int main()
{
	int num = 3, isPrime, i, count = 1;
	long int sum = 0;

	// Loop until we reach 2 million
	while (num < 2000000)
	{
		isPrime = 1;
		i = 0;

		// Check the current number against previous primes (sieve solution)
		while (isPrime && primes[i] <= (int) sqrt(num))
		{
			if (num % primes[i++] == 0)
			{
				isPrime = 0;
			}
		}

		// Add number to list if it is prime
		if (isPrime)
		{
			primes[count++] = num;
		}

		num++;
	}

	// Sum primes
	for (i = 0; i < count; i++)
	{
		sum += primes[i];
	}

	printf("%ld\n", sum);

	return 0;
}
