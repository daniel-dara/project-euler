#include <stdio.h>
#include <string.h>

/* This table will be used to keep track of quotient-remainder pairs.
   When dealing with rational numbers (which every fraction in decimal
   form will produce), if the same quotient and remainder are reached
   a second time during the intermediate steps of long division, it is
   guaranteed that the number will cycle since each of the following
   operations will render the same results as the first time. The max
   quotient is 10 since a divisor of 1 will go into 1*10 10 times and
   all fractions with a denominator higher than 1 will divide into
   the dividend less than 10 times. The max remainder is less than 1000
   since at worst case it is possible the dividend is equal to one less
   than the divisor. */

int table[11][1000]; // [quotient][remainder]

/* given an integer divisor, this function finds the length
   of the cycle in the fraction (1 / divisor). It returns 0 if
   there is no cycle. */
int cycleLength(int divisor)
{
	int dividend = 1, quotient, remainder, index = 1;

	// while there is still a dividend left
	while (dividend != 0)
	{
		// standard long division steps
		dividend *= 10;
		quotient = dividend / divisor;
		dividend = remainder = dividend % divisor;

		// if we've come across this quotient-remainder pair before...
		if (table[quotient][remainder] != 0)
		{
			// then we have a cycle and we can use the index of the
			// pair's first appearance to calculate the cycle length
			return index - table[quotient][remainder];
		}
		else
		{
			// otherwise mark the pair as visited by setting it's
			// value to it's index
			table[quotient][remainder] = index++;
		}
	}

	// if we managed to divide out the dividend,
	// then we reached the end of the decimal number and
	// thus by definition there is no cycle
	return 0;
}

int main()
{
	int longestCycle = 0, longestCycleNumber = 0, i, length;

	// loop over possible denominators
	for (i = 1; i <= 1000; i++)
	{
		// clear the lookup table
		memset(table, 0, sizeof(int) * 11 * 1000);

		// get the cycle length and check if its the largets so far
		if ((length = cycleLength(i)) > longestCycle)
		{
			// if so, record it
			longestCycle = length;
			longestCycleNumber = i;
		}
	}

	printf("%d\n", longestCycleNumber);

	return 0;
}
