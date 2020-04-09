#include <stdio.h>

#define GRID_HEIGHT 20
#define GRID_WIDTH 20

int grid[GRID_HEIGHT][GRID_WIDTH];

int MAX(int a, int b)
{
	return (a > b ? a : b);
}

int MAX4(int a, int b, int c, int d)
{
	return MAX(a, MAX(b, MAX(c, d)));
}

int calcProd(int i, int j, int* iOffsets, int* jOffsets)
{
	int product = 1, k;

	for (k = 0; k < 4; k++)
	{
		if ((i + iOffsets[k]) > GRID_HEIGHT || (j + jOffsets[k]) > GRID_WIDTH)
		{
			return 0;
		}
		else
		{
			product *= grid[i + iOffsets[k]][j + jOffsets[k]];
		}
	}

	return product;
}

int main()
{
	int num, i = -1, j, maxProd = 0;
	FILE* input = fopen("p011.in", "r");

	// read input into grid
	while (i++, fscanf(input, "%d", &num) != EOF)
	{
		grid[i / GRID_WIDTH][i % GRID_WIDTH] = num;
	}

	// declare offsets for calcProd function to use
	int noOffset[] = {0, 0, 0, 0};
	int Offset[] = {0, 1, 2, 3};
	int revOffset[] = {3, 2, 1, 0};

	// loop through grid
	for (i = 0; i < GRID_HEIGHT; i++)
	{
		for (j = 0; j < GRID_WIDTH; j++)
		{
				maxProd = MAX4(calcProd(i, j, Offset, Offset),
				               calcProd(i, j, Offset, noOffset),
				               calcProd(i, j, Offset, revOffset),
				               maxProd);
		}
	}

	printf("%d\n", maxProd);

	return 0;
}
