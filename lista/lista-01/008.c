#include "stdio.h"

int calculate(double g, int x)
{
  double currentG = g;
  int n = 0;
  while (currentG >= 1)
  {
    n += x;
    currentG /= 2;
  }
  return n;
}

int main(void) {
  setvbuf(stdout, NULL, _IONBF, 0);

  double g;
  int x;
  
  printf("Digite a massa inicial e a quantidade de segundos: ");
  scanf("%lf %d", &g, &x);
  
  printf("A massa se tornará menor que 1g em %d segundos\n", calculate(g, x));

  return 0;
}