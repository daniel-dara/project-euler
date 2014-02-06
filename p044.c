#include <stdio.h>
#include <string.h>

#define MAX_PENT 10000000

int pentNumbers[MAX_PENT];
int pentCounter = 0;
int isPent[MAX_PENT];

int main()
{
	memset(isPent, 0, sizeof(int) * MAX_PENT);
	int n, pentN = 1;

	// Generate pentagonal numbers until the nth number is above a MAX_PENT.
	// Record in a list and as a hash.
	for (n = 2; pentN < MAX_PENT; n++)
	{
		isPent[pentN] = 1;
		pentNumbers[pentCounter++] = pentN;
		pentN = n * (3*n - 1) / 2;
	}

	int i = 0, done = 0, j = 1;
	int diff = 0;

	// My solution is to slide two "pointers" through the list of pentagonal numbers
	// until the stated constraints are met. By starting with "i" and "j" as small as possible
	// and incrementing "j" first, I guarantee that the difference between pentNum[i] and
	// pentNum[j] is the smallest possible.
	while (!done)
	{
		if (j < pentCounter && pentNumbers[i] + pentNumbers[j] < MAX_PENT && isPent[pentNumbers[i] + pentNumbers[j]] && isPent[pentNumbers[j] - pentNumbers[i]])
		{
			//done = 1;
			diff++;
			printf("pi:%d pj:%d\n", pentNumbers[i], pentNumbers[j]);
			printf("i:%d j:%d\n", i, j);
			printf("pdif:%d\n\n", pentNumbers[j] - pentNumbers[i]);
			j++;
		}
		else
		{
			if (j >= pentCounter || pentNumbers[i] + pentNumbers[j] < pentNumbers[j +  1])
			{
				i++;
				j = i + 1;

				if (j >= pentCounter)
				{
					done = 2;
				}
			}
			else
			{
				j++;
			}
		}
	}

	printf("diff:%d\n", diff);
	printf("last pent diff:%d\n", pentNumbers[pentCounter-1] - pentNumbers[pentCounter-2]);
	if (done == 2)
	{
		printf("None found.\n");
	}
	else
	{
		printf("pi:%d pj:%d\n", pentNumbers[i], pentNumbers[j]);
		printf("i:%d j:%d\n", i, j);
		printf("pdif:%d\n", pentNumbers[j] - pentNumbers[i]);		
	}

	return 0;
}