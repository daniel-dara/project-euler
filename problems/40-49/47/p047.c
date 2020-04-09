#include <stdio.h>

#define NUM 4

int i = 2;
int primes[1000000] = {0};
int prime_index = 0;

int isInt(double num) {
	return num == (int) num;
}

int isPrime(int num)
{
	for (int i = 0; i < prime_index; i++)
	{
		if (isInt(num / (double) primes[i]))
		{
			return 0;
		}
	}

	primes[prime_index++] = num;
	return 1;
}


int hasDistinctPrimeFactors(int num)
{
	int factors = 0;

	for (int i = 0; i < prime_index; i++)
	{
		if (isInt(num / (double) primes[i]))
		{
			factors += 1;

			if (factors > NUM) {
				return 0;
			}

			while (isInt(num / (double) primes[i]))
			{
				num /= primes[i];

				if (num == 0) {
					return factors == NUM;
				}
			}
		}
	}

	return factors == NUM;
}

int count = 0;
int first = 0;

int main()
{
	while (count < NUM) {
		if (!isPrime(i) && hasDistinctPrimeFactors(i))
		{
			if (count == 0)
			{
				first = i;
			}

			count += 1;
		}
		else
		{
			count = 0;
		}

		i += 1;
	}

	printf("%d\n", first);

	return 0;
}
