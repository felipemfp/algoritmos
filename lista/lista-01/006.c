#include "stdio.h"

int calculateGCD(int a, int b)
{
  int i, x, gcd = 0;
  
  x = a > b ? b : a;
  
  for (i = x; i > 0; i--)
  {
    if (a % i == 0 && b % i == 0)
    {
      gcd = i;
      break;
    }
  }
  
  return gcd;
}

int main(void) {
  setvbuf(stdout, NULL, _IONBF, 0);

  int a, b;
  
  printf("Digite dois números: ");
  scanf("%d %d", &a, &b);
  
  printf("O máximo divisor comum entre eles é %d\n", calculateGCD(a, b));

  return 0;
}