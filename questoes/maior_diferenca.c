/*
 * Escreva um programa que leia 1000 elementos e mostre a maior diferença
 * entre dois elementos consecutivos desse array e em que indices eles estão.
 */

#include <stdio.h>

int main(void)
{
  int i, n = 1000, last, lastIndex, x, y, greatest = 0, arr[n];

  for (i = 0; i < n; i++)
  {
    scanf("%d\n", &arr[i]);
    if (i > 0)
    {
      if (arr[i] - last > greatest)
      {
        greatest = arr[i] - last;
        y = i;
        x = lastIndex;
      }
      else if (last - arr[i] > greatest)
      {
        greatest = last - arr[i];
        y = i;
        x = lastIndex;
      }
      last = arr[i];
      lastIndex = i;
    }
    else
    {
      last = arr[i];
    }
  }

  printf("Maior diferença é: %d\n", greatest);
  printf("Os índices são: %d e %d\n", x, y);
  printf("Os números são: %d e %d\n", arr[x], arr[y]);

  return 0;
}
