#include <iostream>
#include <set>
#include <cmath>

typedef double Int;

const Int MAX_A = 100;
const Int MAX_B = 100;

int main()
{
	std::set<Int> sequence;

	for (int a = 2; a <= MAX_A; a++)
	{
		for (int b = 2; b <= MAX_B; b++)
		{
			sequence.insert(pow(a, b));
		}
	}

	std::cout << sequence.size() << "\n";

	return 0;
}
