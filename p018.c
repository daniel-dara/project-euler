/*
	This is a linear time solution in respect to the amount of data
	in the triangle and it uses only N memory where N is the number
	of rows in the triangle.
*/

#define N 15

#include <stdio.h>
#include <string.h>

int curRow[N];

static inline int MAX(int a, int b) {
	return a > b ? a : b;
}

int main() {
	// Clear row
	memset(curRow, 0, N * sizeof(int));

	int i, row = 0, num, maxPath = 0;
	int leftParent, rightParent, maxParent = 0;

	while (row++ < N) {
		// Reset the column counter
		i = 0;

		// Reset leftParent since there is none for the first column of the row
		leftParent = 0;

		while (i < row) {
			scanf("%d", &num);

			// Get the max between the left and right parent
			maxParent = MAX(leftParent, i < row ? curRow[i] : 0);

			// Store the current right parent to be the next left parent before we overwrite it
			leftParent = curRow[i];

			// Store the running max total for the given column into the row
			curRow[i] = num + maxParent;

			// Keep track of the max total for all columns
			maxPath = maxPath > curRow[i] ? maxPath : curRow[i];

			i++;
		}
	}

	printf("%d\n", maxPath);

	return 0;
}
