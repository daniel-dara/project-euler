#define SIDE 1001
#include <stdio.h>

int main()
{
	int side = 3, number = 1, sum = 1, i;
	
	while (side <= SIDE)
	{
		// sum up the four corners
		for (i = 0; i < 4; i++)
		{
			// increment the number by the side length (-1 for inclusive counting)
			number += side - 1;
			sum += number;
		}

		// the side grows by 2 each spiral
		side += 2;
	}

	printf("%d\n", sum);

	return 0;
}
