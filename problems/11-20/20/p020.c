#include <stdio.h>
#include <string.h>

void multiply(int *product, int multiplier)
{
	int carry = 0, index = 199, digitProduct;

	while (carry != 0 || product[index] != -1)
	{
		if (product[index] != -1)
		{
			 digitProduct = product[index] * multiplier + carry;
		}
		else
		{
			digitProduct = carry;
		}

		product[index--] = digitProduct % 10;
		carry = digitProduct / 10;
	}
}

int main()
{
	int product[200], i, sum = 0;

	memset(product, -1, sizeof(int) * 200);
	product[199] = 1;

	for (i = 2; i <= 100; i++)
	{
		multiply(product, i);
	}

	for (i = 0; i < 200; i++)
	{
		if (product[i] != -1)
		{
			sum += product[i];
		}
	}

	printf("%d\n", sum);

	return 0;
}
