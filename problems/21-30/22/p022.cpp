#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// sum up the character values in str
int char_sum(string str)
{
	int sum = 0;

	for (unsigned int i = 0; i < str.length(); i++)
	{
		sum += str[i] - 'A' + 1;
	}

	return sum;
}

int main()
{
	ifstream input;
	input.open("p022.in", ios::in);
	vector<string> names;

	// read in the names
	while (!input.eof())
	{
		string name;
		getline(input, name, ',');
		names.push_back(name.substr(1, name.length() - 2));
	}

	sort(names.begin(), names.end());

	int total = 0;

	// compute and sum their values
	for (unsigned int i = 0; i < names.size(); i++)
	{
		total += (i + 1) * char_sum(names[i]);
	}

	cout << total << endl;

	return 0;
}
