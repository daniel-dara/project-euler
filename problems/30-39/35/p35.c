#include <stdio.h>
#include <math.h>

int primes[1000000] = {0}, counter = 0;
int orderedprimes[1000000] = {0};

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

void generatePrimes(int lessThan) {
  int num = 2;

  while(num < lessThan) {
    int i, prime = 1;

    for(i = 0; i < counter && prime; i++)
      prime = (num % primes[i] != 0);

    if(prime)
      primes[counter++] = num;

    num++;
  }
}

int cycleNum(int num) {
  char *n = itoa(num);
  for(i = 0
}

int main() {
  generatePrimes(1000000);

  int i;
  for(i = 0; i < counter; i++)
    orderedprimes[primes[i]] = 1;

  

}
