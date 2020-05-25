#include <stdio.h>
#include <math.h>

void decimalToFraction(double number, int* num, int* denom) {
  *denom = 1;

  while(floor(number) != number) {
    number *= 10;
    *denom *= 10;
  }

  *num = number;

  int i;
  for(i = (int) sqrt(number); i > 0; i--)
    if(*num % i == 0 && *denom % i == 0) {
      *num /= i;
      *denom /= i;
    }
}

int isNon(int num, int denom) {
  double val1 = (double) num / denom;
  double val2 = (double) (num / 10) / (denom % 10);

  if(val1 == val2 && num % 10 == denom / 10)
    return 1;

  return 0;
}

int main() {
  int i, j, nums[1000] = {0}, denoms[1000] = {0}, counter = 0;

  for(i = 10; i < 100; i++)
    for(j = i + 1; j < 100; j++)
      if(isNon(i, j)) {
          nums[counter] = i;
          denoms[counter++] = j;
      }

  for(i = 0; i < 1000; i++)
    if(nums[i] != 0)
      printf("%d/%d\n", nums[i], denoms[i]);

  int num = 1, denom = 1;
  for(i = 0; i < 4; i++) {
    num *= nums[i];
    denom *= denoms[i];
  }

  printf("initial: %d/%d\n", num, denom);

  decimalToFraction((double) num / denom, &num, &denom);

  printf("final: %d/%d", num, denom);

}
