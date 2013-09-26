#include <stdio.h>

int main(){
	int total = 0, temp, term[] = {1, 2};

	while (term[1] < 4000000) {
		// increment total if term is even
		if (term[1] % 2 == 0) total += term[1];

		temp = term[0]; // save first term
		term[0] = term[1]; // move second term to first term
		term[1] += temp; // sum previous two terms to find new second term
	}

	printf("%d\n", total);

	return 0;
}
