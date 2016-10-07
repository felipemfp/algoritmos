/*
 * Escreva um programa que calcule o fatorial de forma recursiva.
 */

#include <stdio.h>

int recursive_factorial(int x)
{
  if (x == 0)
  {
    return 1;
  }

  return x * recursive_factorial(x - 1);
}

int main(void) {
  printf("%d\n", recursive_factorial(6)); // expected: 720
  return 0;
}
