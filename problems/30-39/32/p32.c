#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int pans[1000] = {0}, counter = 0;

inline int Digits(int num) {
  return log(num) / log(10) + 1;
}

char* itoa(int num) {
  int size = Digits(num);
  char* a = malloc(size + 1);
  int i = size;

  a[i--] = '\0';
  while(num != 0) {
    a[i--] = (num % 10) + '0';
    num /= 10;
  }

  return a;
}

int checkDigits(int num, int* digits) {
  int i;
  char* n = itoa(num);

  for(i = 0; i < Digits(num); i++)
    if(n[i] == '0' || digits[n[i] - '0']++) {
      //printf("n[%d] = %d\n", i, n[i]);
      return 0;
    }

  return 1;
}

int isPan(int num1, int num2) {
  int num3 = num1 * num2;
  if(Digits(num1) + Digits(num2) + Digits(num3) != 9)
    return 0;

  int i, digits[10] = {0};

  if(checkDigits(num1, digits))
    if(checkDigits(num2, digits))
      if(checkDigits(num3, digits))
        return 1;

  return 0;
}

int main() {
  int i, j;
  for(i = 1; i < 1000; i++)
    for(j = 1; j < 10000; j++) {
      if(isPan(i, j))
        pans[counter++] = i*j;
    }

  // clean duplicates
  for(i = 0; i < counter; i++)
    for(j = 0; j < counter; j++)
      if(pans[i] == pans[j] && i != j)
        pans[j] = 0;

  int sum = 0;
  for(i = 0; i < counter; i++)
    sum += pans[i];

  printf("sum: %d", sum);
}
