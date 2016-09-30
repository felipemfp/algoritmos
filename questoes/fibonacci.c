/*
 * Escreva um programa que calcule o n-ésimo número da Sequência de Fibonacci
 * de forma recursiva.
 */

#include <stdio.h>

int recursive_fibonacci(int n)
{
  if (n < 2)
  {
    return n;
  }
  return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}


int main(void) {
  printf("%d\n", recursive_fibonacci(10)); // expected 55
  return 0;
}
