#include <stdio.h>

int main()
{
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month = 1, year = 1901, dayOfWeek = 3, numberOfSundays = 0;

	while (year < 2000 || month < 12)
	{
		if (dayOfWeek == 1)
		{
			numberOfSundays++;
		}

		dayOfWeek += daysInMonth[month - 1];

		if (year % 4 == 0 && year % 400 != 0 && month == 2)
		{
			dayOfWeek++;
		}

		if (++month > 12)
		{
			year++;
			month = 1;
		}

		dayOfWeek %= 7;
	}

	printf("%d\n", numberOfSundays);

	return 0;
}
