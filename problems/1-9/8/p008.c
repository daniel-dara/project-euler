#include <stdio.h>
#include <stdlib.h>

#define N 1000

/* Runtime Analysis:
   k = digits in product = 4
   N = digits in number = 1000

   Since k is small in this problem, a runtime of O(kN), which this
   solution has, is not bad. If k were closer to N then runtime is exponential.
   A better solution would then be to use a queue and keep a running
   product by multiplying the next number coming in and dividing
   the number going out. This alone is still worst case kN though since a digit
   of 0 forces the entire product to be recalculated and thus a
   number of all 0s would run the same as the solution below. However
   on average it would be much better and for input with no 0s it
   would have linear run time O(N). */

int main()
{
	// p008.in contains the 1,000 digit number
	int n[N], i = 0, product = 0, maxProduct = 0;
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

	fclose(input);

	for (i = 0; i < N - 4; i++)
	{
		// Recalculate product and update max
		maxProduct = ((product = n[i] * n[i+1] * n[i+2] * n[i+3] * n[i+4]) > \
		               maxProduct ? product : maxProduct);
	}

	printf("%d\n", maxProduct);

	return 0;
}
