#include <iostream>
#include <string>

using namespace std;

int limit = 1000000;

// elicit all permutations of string rest
string permutate(string str, string rest)
{
	if (rest.length() == 0)
	{
		if (--limit == 0)
		{
			return str;
		}
		else
		{
			return "";
		}
	}

	// loop over all possible starting characters
	for (unsigned int i = 0; i < rest.length(); i++)
	{
		string temp = rest;

		// add new starting character to current
		// permutation and erase it from our original
		// string
		string result = permutate(str + temp[i], rest.erase(i, 1));

		if (!result.empty())
		{
			return result;
		}

		// restore the original string since a different
		// character will be removed next time
		rest = temp;
	}

	return "";
}

int main()
{
	cout << permutate("", "0123456789") << endl;

	return 0;
}
