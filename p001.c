#include <stdio.h>

int main(){
	int i, total = 0;

	// loop through all natural numbers
	for (i = 1; i < 1000; i += 1)
		if (i % 3 == 0 || i % 5 == 0)
			total += i; // add to total if division by 3 or 5 has no remainder

	printf("%d\n", total);

	return 0;
}
