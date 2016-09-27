#include "stdio.h"

int main(void)
{
  setvbuf(stdout, NULL, _IONBF, 0);

  double n1, n2, media;

  printf("Digite sua nota do primeiro bimestre: ");
  scanf("%lf", &n1);

  printf("Digite sua nota do segundo bimestre: ");
  scanf("%lf", &n2);

  media = ((n1 * 2) + (n2 * 3)) / 5;

  if (media >= 6)
  {
    printf("Você foi aprovado!");
  }
  else if (media >= 2)
  {
    printf("Você está em recuperação!");
  }
  else
  {
    printf("Você está reprovado! :(");
  }

  printf(" Com média %.2f.\n", media);

  return 0;
}
