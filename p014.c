#include <stdio.h>

int countChain(long long int num) {
	int length = 0;

	// iterate through chain
	while (length++, num != 1)
		if (num % 2)
			num = 3 * num + 1;
		else
			num /= 2;

	return length;
}

int main() {
	int i, longestChain = 0, chain, num = 0;

	for (i = 1; i < 1000000; i++) {
		if ((chain = countChain(i)) > longestChain) {
			longestChain = chain;
			num = i;
		}
	}

	printf("%d\n", num);

	return 0;
}
