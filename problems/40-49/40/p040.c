#include <stdio.h>
#include <math.h>

// returns the nth least significant digit from 'num'
int getDigit(int num, int n)
{
	int i = 0;

	while (i++ < n)
	{
		num /= 10;
	}

	return num % 10;
}

// returns the total number of digits in 'num'
int digitCount(int num)
{
	return log10(num) + 1;
}

// returns the nth digit in Champernowne's constant
int nthDigit(int n)
{
	int i = 1, digits = 1;

	while (digits < n)
	{
		i++;
		digits += digitCount(i);
	}

	return getDigit(i, (digits - n));
}

int main()
{
	int i = 1, product = 1;

	for (i = 1; i < 1000000; i *= 10)
	{
		product *= nthDigit(i);
	}

	printf("%d\n", product);

	return 0;
}
