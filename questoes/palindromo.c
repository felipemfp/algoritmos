/*
 * Escreva um programa que recebe um nome ou uma frase e verifique se
 * é um palíndromo.
 */

#include <stdio.h>
#include <string.h>

char isLetter(char c)
{
  if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
  {
    return 1;
  }
  return 0;
}

int main(int argc, char ** argv) {
  int i, j, len = strlen(argv[1]);
  for (i = 0, j = len - 1; i < len; i++, j--) {
    while (!isLetter(argv[1][i]))
    {
      i++;
      if (len <= i)
      {
        printf("Argumento inválido.\n");
        return 1;
      }
    }
    while (!isLetter(argv[1][j]))
    {
      j--;
      if (j <= 0)
      {
        printf("Argumento inválido.\n");
        return 1;
      }
    }
    if (argv[1][i] >= 97)
    {
      argv[1][i] = argv[1][i] - 'a' + 'A';
    }
    if (argv[1][j] >= 97)
    {
      argv[1][j] = argv[1][j] - 'a' + 'A';
    }
    if (argv[1][i] != argv[1][j])
    {
      printf("Não é um palíndromo.\n");
      return 0;
    }
    if (i >= j)
    {
      break;
    }
  }
  printf("É um palíndromo.\n");
  return 0;
}
