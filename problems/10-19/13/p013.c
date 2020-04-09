#include <stdio.h>

// The sum of 100 50-digit numbers is at worst 9.99...e50 * 100 = 9.99...e52
// so we are guaranteed 52 digits or less
int sum[52];
int numbers[100][50];

int main()
{
	int i = 0;
	char c;
	FILE* input = fopen("p013.in", "r");

	// read in the numbers
	while (fscanf(input, "%c", &c) != EOF)
	{
		if (c != '\n')
		{
			numbers[i / 50][i % 50] = c - '0';
			i++;
		}
	}

	int col = 49, carry = 0, sumCol;

	// loop from right to left summing columns until we pass the
	// 50th digit and don't have any carry
	while (col >= 0 || carry)
	{
		sumCol = carry; // initialize to carry from the last sum

		if (col >= 0)
		{
			for (i = 0; i < 100; i++)
			{
				sumCol += numbers[i][col]; // sum a column
			}
		}

		// put the last digit of the column's sum into the total sum
		sum[col + 2] = sumCol % 10;

		// divide by 10 and carry
		carry = sumCol / 10;

		col--;
	}

	// only print the first 10 digits as per the question
	for (i = 0; i < 10; i++)
	{
		printf("%d", sum[i]);
	}

	printf("\n");

	return 0;
}
