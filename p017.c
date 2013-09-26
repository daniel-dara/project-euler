#include <stdio.h>
#include <string.h>
#define L(x) sizeof(x) - 1

int ones[] = {L("zero"), L("one"), L("two"), L("three"), L("four"), L("five"),
				L("six"), L("seven"), L("eight"), L("nine"), L("ten")};

int tens[] = {L("ten"), L("twenty"), L("thirty"), L("forty"),
				L("fifty"), L("sixty"), L("seventy"), L("eighty"), L("ninety")};

int teens[] = {L("eleven"), L("twelve"), L("thirteen"),
				 L("fourteen"), L("fifteen"), L("sixteen"), L("seventeen"),
				 L("eighteen"), L("nineteen")};

int hundred = L("hundred");
int thousand = L("thousand");

inline int letterCount(int num)
{
	int count = 0;

	if (num % 100 == 0)
	{
		if (num == 0)
		{
			count = ones[0];
		}
	}
	else if (num % 100 <= 10)
	{
		// count ones
		count += ones[num % 100];
		printf("ones: %d\n", num % 100);
	}
	else if (num % 100 < 20)
	{
		// count teens
		count += teens[num % 100 - 11];
	}
	else
	{
		// tens
		count += tens[(num % 100) / 10 - 1];

		// -ones
		if (num % 10 != 0)
		{
			count += ones[num % 10];
		}
	}

	if ((num % 1000) / 100 != 0)
	{
		// count hundreds
		count += ones[num / 100] + hundred;

		if (num % 100 > 0)
		{
			count += L("and");
		}
	}

	if (num == 1000)
	{
		count = ones[1] + thousand;
	}

	return count;
}

int main()
{
	int totalLetters = 0, i;

	for (i = 1; i <= 1000; i++)
	{
		totalLetters += letterCount(i);
		printf("number: %d count: %d\n", i, letterCount(i));
	}

	printf("%d\n", totalLetters);

	return 0;
}
