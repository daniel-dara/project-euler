#include <stdio.h>
#include <stdlib.h>

/* This is an extremely short solution to the problem however
   it takes advantage of the small size of the input. For an
   optimized solution that can compute the answer while reading
   in the data see p008b.c. */
int main()
{
	// p008.in contains the 1,000 digit number
	int n[1000], i = 0, product = 0, maxProduct = 0;
	char c;
	FILE* input = fopen("p008.in", "r");

	// Read input into array
	while (fscanf(input, "%c", &c) != EOF)
	{
		if (c != '\n')
		{
			n[i++] = c - '0'; // convert c to an integer
		}
	}

	for (i = 0; i < 1000 - 4; i++)
	{
		// Recalculate product and update max
		maxProduct = ((product = n[i] * n[i+1] * n[i+2] * n[i+3] * n[i+4]) > \
		               maxProduct ? product : maxProduct);
	}

	printf("%d\n", maxProduct);

	return 0;
}
