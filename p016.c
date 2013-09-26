#include <stdio.h>
#include <string.h>

// ceiling(1000 * log10(2)) == 302
int finalNumber[302];

int main() {
	memset(finalNumber, 0, sizeof(int) * 302);

	finalNumber[301] = 2;

	int i, col, prodCol, carry;

	// Loop up to given power
	for (i = 1; i < 1000; i++) {
		carry = 0;

		// Multiply number in finalNumber by 2
		// (Loop through columns multiplying digits by 2)
		for (col = 301; col >= 0; col--) {
			// Inherit any previous carry value
			prodCol = carry;

			// Multiply the digit by two
			prodCol += finalNumber[col] * 2;

			// Keep the right-most digit from digit product as the final product's digit
			finalNumber[col] = prodCol % 10;

			// Divide by 10 (remove right-most digit) and store in carry
			carry = prodCol / 10;
		}
	}

	int sum = 0;

	// sum the digits of the final number
	for (i = 0; i < 302; i++) {
		sum += finalNumber[i];
	}

	printf("%d\n", sum);	

	return 0;
}
