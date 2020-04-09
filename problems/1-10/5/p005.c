#include <stdio.h>

// brute force method
int main()
{
	long unsigned int num = 1, i, isDivisible = 0;

	// loop until a number is divisible by 1-20
	while (!isDivisible)
	{
		num++;
		isDivisible = 1;

		// only check 11-20 since factors 1-10 are contained in 11-20
		for (i = 11; i <= 20 && isDivisible; i++)
		{
			if (num % i != 0)
			{
				isDivisible = 0; 
			}
		}
	}

	printf("%lu\n", num);

	return 0;
}
