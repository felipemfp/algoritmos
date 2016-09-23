#include "stdio.h"

int main(void) {
  setvbuf(stdout, NULL, _IONBF, 0);

  int i, n, sum = 0;
  
  printf("Digite um número: ");
  scanf("%d", &n);
  
  for (i = 1; i <= n; i++)
  {
    sum += i;
    printf("%5d ", i);
    if (i % 5 == 0 || i == n)
    {
      printf("\n");
    }
  }
  
  printf("E a soma é: %d\n", sum);

  return 0;
}