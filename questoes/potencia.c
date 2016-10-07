/*
 * Escreva um programa que calcule a potência de forma recursiva.
 */

#include <stdio.h>

double recursive_pow(double x, int y)
{
  if (y == 0)
	{
    return 1;
  }

  if (y == 1)
  {
    return x;
  }

  return x * recursive_pow(x, y - 1);
}

int main(void) {
  printf("%lf\n", recursive_pow(2, 2)); // expected: 4.00000
  return 0;
}
