#include <stdio.h>

int isPan(int num)
{
	// if num is greater than the greatest pandigital return false
	if (num > 987654321)
	{
		return 0;
	}

	int digits = 0;

	/* Use bits to represent which digits we've seen
		this solution would fail for a number with digits 1-9 AND
		repeating digits however we avoid this by making sure num
		is not large enough to have digits 1-9 and repeats. */
	while (num > 0)
	{
		digits |= 1 << num % 10;
		num /= 10;
	}

	// the least significant bits (1-9) should be set to 1 resulting
	// in the integer being equal to 1022 (2^10 - 2)
	return (digits == 1022);
}

int main()
{
	int i, maxPan = 0;

	/*
	   brute force, loop through all possible integers
	   anything past 10,000 won't work since our pandigital
	   number is only 9 digits and for an n > 1 using 10,000
	   produces at least a 10 digit number
	*/
	for (i = 1; i < 10000; i++)
	{
		int product, count = 0, num = 0, n = 0;

		// Loop for n until our digit count reaches or passes 9
		while (count < 9)
		{
			n++;
			product = i * n; // calculate our n product

			int power = 1;
			while (power <= product)
			{
				// find the smallest power of 10 > product
				power *= 10;
			}

			// from left to right concatenate the digits of product to num
			while (product > 0)
			{
				power /= 10;            // since power starts off > product, divide out a 10 first
				num *= 10;              // shift digits in num left
				num += product / power; // add left most digit of product to num
				product %= power;       // remove left most digit of product
				count++;                // increment total digit count
			}
		}

		// Check that num meets conditions of the problem to be a max pandigital
		if (count == 9 && n > 1 && num > maxPan && isPan(num))
		{
			maxPan = num;
		}
	}

	printf("%d\n", maxPan);

	return 0;
}
