#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

using namespace std;

int isPrime(int num) {
	int i = 2, root = sqrt(num), isPrime = 1;

	while (isPrime && i <= root) {
		isPrime = num % i++ != 0;
	}

	return isPrime;
}

int main() {
	int num, max = 0;
	string pan = "123456789";

	while (max == 0) {
		do {
			num = atoi(pan.c_str());

			if (num > max && isPrime(num))
				max = num;
		} while (next_permutation(pan.begin(), pan.end()));

		pan = pan.substr(0, pan.length() - 1);
	}

	cout << max << endl;

	return 0;
}
