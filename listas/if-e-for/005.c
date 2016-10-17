#include "stdio.h"

char isPrime(int n)
{
  int i;
  if (n < 2)
  {
    return 0;
  }
  if (n == 2)
  {
    return 1;
  }
  if (n % 2 == 0)
  {
    return 0;
  }
  for (i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      return 0;
    }
  }
  return 1;
}

int main(void)
{
  setvbuf(stdout, NULL, _IONBF, 0);

  int n;

  printf("Digite um número: ");
  scanf("%d", &n);

  if (isPrime(n))
  {
    printf("É primo!\n");
  }
  else
  {
    printf("Não é primo! :(\n");
  }

  return 0;
}
