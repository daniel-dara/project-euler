#define SIZE 1000

#include <stdio.h>
#include <string.h>

// calculates the sum of 'a' and 'b' and stores result in 'b'
inline void sum(int* a, int* b)
{
	int i = SIZE, sum, carry = 0;

	// This loop sums each column of the input arrays.
	// I'm not checking for overflow since the problem statement
	// states the number will contain 1,000 digits
	while (--i >= 0)
	{
		sum = a[i] + b[i] + carry;
		carry = sum / 10;
		b[i] = sum % 10;
	}
}

int main()
{
	int a[SIZE], b[SIZE], temp[SIZE], term = 1;
	memset(a, 0, sizeof(int) * SIZE);
	memset(b, 0, sizeof(int) * SIZE);

	a[SIZE - 1] = 0;
	b[SIZE - 1] = 1;

	// calculate fibonocci sequence
	while (b[0] == 0)
	{
		// make 'a' back up of 'b'
		memcpy(temp, b, sizeof(int) * SIZE);

		sum(a, b);
		term++;

		// the old 'b' is the new 'a'
		memcpy(a, temp, sizeof(int) * SIZE);
	}

	printf("%d\n", term);

	return 0;
}
