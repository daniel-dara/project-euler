#include <stdio.h>

const int sum = 200;
const int currency[] = {1, 2, 5, 10, 20, 50, 100, 200};
const int numOfCurrencies = 8;

int subsetsOfSum(int amount, int startingCurrency)
{
	if (amount == sum)
	{
		// sum was reached, success
		return 1;
	}
	else if (amount > sum)
	{
		// we passed sum, failure
		return 0;
	}

	int i, ways = 0;

	/*
	   Recursively add each of the other types of currency left.
	   We start at startingCurrency to avoid double counting.
	   Once a higher currency is added, that branch of the recursion
	   should no longer add lower numbers. We don't want to count
	   both 1 + 1 + 5 and 1 + 5 + 1!
	*/
	for (i = startingCurrency; i < numOfCurrencies; i++)
	{
		ways += subsetsOfSum(amount + currency[i], i);
	}

	return ways;
}

int main()
{
	printf("%d\n", subsetsOfSum(0,0));

	return 0;
}
