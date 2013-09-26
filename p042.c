#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline eval(char* str) {
	int sum = 0, i = 0;

	while (str[i] != '\0') {
		sum += str[i++] - 'A' + 1;
	}

	return sum;
}

int main() {
	FILE* input = fopen("p042.in", "r");
	char* word = malloc(sizeof(char) * 20);
	int total = 0;

	while (fscanf(input, "\"%[A-Z]\",", word) != EOF) {
		double quad_plus = -.5 + sqrt(.25 - 2 * -eval(word));
		total += (quad_plus - (int) quad_plus == 0);
	}

	printf("%d\n", total);

	return 0;
}
