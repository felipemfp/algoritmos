#include <stdio.h>

int indexOf(int* arr, int len, int lookfor)
{
  int i;
  for (i = 0; i < len; i++)
  {
    if (arr[i] == lookfor)
    {
      return i;
    }
  }
  return -1;
}

int indexOfGreatest(int* arr, int len, int ignore)
{
  int i, greatest = 0, indGreatest = -1;
  if (0 <= ignore && ignore < len)
  {
    greatest = arr[ignore];
  }
  for (i = 0; i < len; i++)
  {
    if (i == ignore)
    {
      i++;
    }
    if (arr[i] >= greatest)
    {
      greatest = arr[i];
      indGreatest = i;
    }
  }
  return indGreatest;
}

int main(void)
{
  int lenZones = 5,
      lenMayors = 4,
      lenAldermen = 5,
      nullVotes = 0,
      aldermanIndex,
      mayorIndex,
      mayorSecondIndex;

  int mayors[] = { 13, 21, 25, 12 };
  char * mayorsName[] = { "Marcelo Bonito", "Robson Dantas", "Caetando Veloso", "Carlos Silva" };
  int mayorsVotes[] = { 0, 0, 0, 0 };

  int aldermen[] = { 20000, 20001, 20002, 20003, 20004 };
  char * aldermenName[] = { "Monica", "Chandler", "Ross", "Rachel", "Phoebe" };
  int aldermenVotes[] = { 0, 0, 0, 0, 0 };

  int zones[] = { 1, 2, 3, 4, 69 };
  int numPerZone[] = { 3, 2, 1, 1, 2 };

  int i, j;
  for (i = 0; i < lenZones; i++)
  {
    printf("Zona Eleitoral #%d\n", zones[i]);
    for (j = 0; j < numPerZone[i]; j++)
    {
      int aldermanVote, mayorVote;
      printf("Olá, Eleitor %d\n", j + 1);
      printf("Informe seu voto para vereador: ");
      scanf("%d", &aldermanVote);
      aldermanIndex = indexOf(aldermen, lenAldermen, aldermanVote);
      if (aldermanIndex > -1)
      {
        aldermenVotes[aldermanIndex] += 1;
        printf("Você votou em '%s' para vereador.\n", aldermenName[aldermanIndex]);
      }
      else
      {
        printf("Você votou nulo para vereador.\n");
      }
      printf("Informe seu voto para prefeito: ");
      scanf("%d", &mayorVote);
      mayorIndex = indexOf(mayors, lenMayors, mayorVote);
      if (mayorIndex > -1)
      {
        mayorsVotes[mayorIndex] += 1;
        printf("Você votou em '%s' para prefeito.\n", mayorsName[mayorIndex]);
      }
      else
      {
        printf("Você votou nulo para prefeito.\n");
      }
      printf("-------------\n\n");
    }
    printf("\n=============\n\n");
  }

  mayorIndex = indexOfGreatest(mayorsVotes, lenMayors, -1);
  mayorSecondIndex = indexOfGreatest(mayorsVotes, lenMayors, mayorIndex);
  if (mayorSecondIndex > -1)
  {
    printf("Os prefeitos '%s' e '%s' disputarão o segundo turno.\n", mayorsName[mayorIndex], mayorsName[mayorSecondIndex]);
  }
  else
  {
    printf("O prefeito eleito foi '%s'.\n", mayorsName[mayorIndex]);
  }
  aldermanIndex = indexOfGreatest(aldermenVotes, lenAldermen, -1);
  printf("O vereador mais votado foi '%s'.\n", aldermenName[aldermanIndex]);
  return 0;
}
