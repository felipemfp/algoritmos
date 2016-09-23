#include "stdio.h"

int calculatePow(int n, int x)
{
  int i, r = 1;
  for (i=0;i<x;i++)
  {
    r *= n;
  }
  return r;
}

int main(void) {
  setvbuf(stdout, NULL, _IONBF, 0);

  int n, x;
  
  printf("Digite um número: ");
  scanf("%d", &n);
  
  printf("Digite a potência: ");
  scanf("%d", &x);
  
  printf("%d^%d = %d\n", n, x, calculatePow(n, x));

  return 0;
}