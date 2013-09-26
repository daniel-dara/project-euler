#include <stdio.h>

int primes[10001], count = 0;

inline int isPrime(int num)
{
	int isPrime = 1, i = 0;

	// Check that the given number is not divisible by any
	// previously recorded primes
	while (isPrime && i < count)
	{
		isPrime = (num % primes[i++] != 0);
	}

	return isPrime;
}

int main()
{
	int num = 2;	

	// Loop until 10,001 primes have been calculated
	while (count < 10001)
	{
		if (isPrime(num))
		{
			primes[count++] = num;
		}
		
		num++;
	}

	printf("%d\n", primes[10000]);

	return 0;
}
