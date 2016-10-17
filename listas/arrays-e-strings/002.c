#include <stdio.h>

int main(void)
{
  setvbuf(stdout, NULL, _IONBF, 0);

  int i, n, lenUp = 0, lenDown = 0;

  printf("Por favor, defina a quantidade de números:");
  scanf("%d\n", &n);

  double arr[n], up[n], down[n], total = 0.0, average;

  for (i = 0; i < n; i++)
  {
    scanf("%lf", &arr[i]);
    total = total + arr[i];
  }

  average = total / n;

  for (i = 0; i < n; i++)
  {
    if (arr[i] >= average)
    {
      up[lenUp] = arr[i];
      lenUp++;
    }
    else
    {
      down[lenDown] = arr[i];
      lenDown++;
    }
  }

  printf("O total é: %.3lf\n", total);
  printf("A média é: %.3lf\n", average);

  printf("Temos %d números acima da média:\n", lenUp);
  for (i = 0; i < lenUp; i++)
  {
    printf("%.3lf ", up[i]);
    if ((i > 0 && i % 5 == 0) || i == lenUp - 1)
    {
      printf("\n");
    }
  }

  printf("Temos %d números abaixo da média:\n", lenDown);
  for (i = 0; i < lenDown; i++)
  {
    printf("%.3lf ", down[i]);
    if ((i > 0 && i % 5 == 0) || i == lenDown - 1)
    {
      printf("\n");
    }
  }

  return 0;
}
