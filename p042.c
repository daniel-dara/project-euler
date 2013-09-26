#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline int eval(char* str)
{
	int sum = 0, i = 0;

	while (str[i] != '\0')
	{
		sum += str[i++] - 'A' + 1;
	}

	return sum;
}

int main()
{
	int total = 0;
	char* word = malloc(sizeof(char) * 20);
	FILE* input = fopen("p042.in", "r");

	while (fscanf(input, "\"%[A-Z]\",", word) != EOF)
	{
		double quad_plus = -0.5 + sqrt(0.25 - 2 * -eval(word));
		total += (quad_plus - (int) quad_plus == 0);
	}

	printf("%d\n", total);

	return 0;
}
