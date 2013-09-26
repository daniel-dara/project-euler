#include <stdio.h>

/*	This solution is longer than p008.c but it is capable of finding
	the max product of k consecutive digits in an n digit number in one pass.
	This is opposed to the fastest method (given small input) which is to
	simply re-calculate the k digit product for all i < n - 5 digits.
	That method only works as long as k is relatively small and not
	proportional to n. */

inline int char_to_int(char c)
{
	return c - '0';
}

int main()
{
	int i, maxProduct = 0, product = 1;
	char digits[] = {0, 0, 0, 0, 0}, deadDigit, c;
	FILE* input = fopen("p008.in", "r");

	while (fscanf(input, "%c", &c) != -1)
	{
		if (c != '\n')
		{
			// Save the digit being erased
			deadDigit = digits[0];

			// Shift digits left
			for (i = 0; i < 4; i++)
			{
				digits[i] = digits[i + 1];
			}

			// Store most recent digit
			digits[4] = c;

			// Accumulate product
			product *= char_to_int(c);

			// Check that we've read 5 numbers
			if (digits[0] != 0)
			{
				// Check that we really have a 6th number to divide out
				if (deadDigit != 0)
				{
					// Take the digit erased out of the product
					if (deadDigit == '0')
					{
						// Rather than divide by 0, we must recompute the product
						for (product = 1, i = 0; i < 5; i++)
						{
							product *= char_to_int(digits[i]);
						}
					}
					else
					{
						// otherwise we can safely divide out the number
						product /= char_to_int(deadDigit);
					}
				}

				// Check product against max
				if (product > maxProduct)
				{
					maxProduct = product;
				}
			}
		}
	}

	printf("%d\n", maxProduct);

	return 0;
}
