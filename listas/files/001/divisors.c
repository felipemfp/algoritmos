#include <stdio.h>
#include "divisors.h"

int generateDivisors(unsigned long int num, FILE * file)
{
  unsigned long int i = 1;
  for (i; i<=num; i++) {
    if (num % i == 0) {
      fprintf(file, "%ld\n", i);
    }
  }
  return 0;
}
