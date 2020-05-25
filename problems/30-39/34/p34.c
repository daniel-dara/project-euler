#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline int Digits(int num) {
  return log(num) / log(10) + 1;
}

double fact(double num) {
  if(num == 0)
    return 1;
  else
    return fact(num - 1) * num;
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

int main() {
  int i, j, total = 0;

  for(i = 3; i < 1000000; i++) {
    double sum = 0;
    char *num = itoa(i);

    for(j = 0; num[j] != 0 && sum <= i; j++)
      sum += fact(num[j] - '0');

    if(sum == i) {
      total += sum;
      printf("i=%d\n", i);
    }
  }

  printf("total: %d", total);
}
