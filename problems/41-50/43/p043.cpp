#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int i, primes[] = {2, 3, 5, 7, 11, 13, 17};
	long int num, total = 0;
	string pan = "0123456789";

	do
	{
		num = atol(pan.c_str());

		int divisible = 1;

		for (i = 0; i < 7 && divisible; i++)
		{
			if (atoi(pan.substr(i + 1, 3).c_str()) % primes[i] != 0)
			{
				divisible = 0;
			}
		}

		if (divisible)
		{
			total += num;
		}
	}
	while (next_permutation(pan.begin(), pan.end()));

	pan = pan.substr(0, pan.length() - 1);

	cout << total << endl;

	return 0;
}
