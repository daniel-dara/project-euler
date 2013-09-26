#include <stdio.h>
#include <string.h>

long long int grid[21][21];

long long int routes(int i, int j) {
	// return if out of bounds
	if (i < 0 || j < 0)
		return 0;

	// if route total is already recorded, return
	if (grid[i][j] != 0)
		return grid[i][j];
	else
		// calculate and store total
		grid[i][j] = routes(i - 1, j) + routes(i, j - 1);

	return grid[i][j];
}

int main() {
	memset(grid, 0, sizeof(long long int) * 21 * 21);

	grid[0][0] = 1; // there is 1 way to the upper left corner

	printf("%lld\n", routes(20,20));

	return 0;
}
