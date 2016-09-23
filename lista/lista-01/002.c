#include "stdio.h"

int main(void) {
  setvbuf(stdout, NULL, _IONBF, 0);

  int a, b, c;
  
  printf("Digite três inteiros na ordem que você quiser: ");
  scanf("%d %d %d", &a, &b, &c);
  
  printf("Em ordem crescente: ");
  if (a < b && a < c)
  {
    if (b < c) 
    {
      printf("%d %d %d", a, b, c);  
    }
    else 
    {
      printf("%d %d %d", a, c, b);
    }
  }
  else if (b < c)
  {
    if (a < c)
    {
      printf("%d %d %d", b, a, c);
    }
    else
    {
      printf("%d %d %d", b, c, a);
    }
  }
  else
  {
    if (a < b)
    {
      printf("%d %d %d", c, a, b);
    }
    else 
    {
      printf("%d %d %d", c, b, a);
    }
  }
  
  printf("\n");

  return 0;
    
}