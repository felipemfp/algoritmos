/*
 * Escreva um programa que leia um array de N números reais e calcule a
 * média dos números. O programa deve mostrar quantos são e quais são os
 * valores acima da média, quantos são e quais são os valores abaixo da
 * média e qual o desvio padrão dos valores.
 */

#include <stdio.h>

int main(void)
{
  setvbuf(stdout, NULL, _IONBF, 0);

  int i, n, lenUp = 0, lenDown = 0;

  printf("Por favor, defina a quantidade de números:");
  scanf("%d\n", &n);

  double arr[n], up[n], down[n], total = 0.0, average, totalDeviation, stdDeviation;

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
    totalDeviation += arr[i] > average ? arr[i] - average : average - arr[i];
  }

  stdDeviation = totalDeviation / n;

  printf("O total é: %.3lf\n", total);
  printf("A média é: %.3lf\n", average);
  printf("O desvio padrão é: %.3lf\n", stdDeviation);

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
