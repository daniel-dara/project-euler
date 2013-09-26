#include <stdio.h>

// return 1 if num is a palindrome, 0 if not
inline int isPal(int num)
{
	int revNum = 0, temp = num;

	// create reverse of num in revNum
	while (temp != 0)
	{
		revNum *= 10;        // scoot digits in revNum to the left
		revNum += temp % 10; // add the last digit from temp to revNum
		temp /= 10;          // erase last digit in temp
	}

	// check if num is equal to its reverse num
	if (num == revNum)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int i, j, maxPal = 0;

	// brute force search
	for (i = 0 ; i < 1000 ; i++)
	{
		for (j = 0 ; j < 1000 ; j++)
		{
			// update maxPal if i * j is a palinrome and greater than the max
			if (i * j > maxPal && isPal(i * j))
			{
				maxPal = i * j;
			}
		}
	}

	printf("%d\n", maxPal);

	return 0;
}
