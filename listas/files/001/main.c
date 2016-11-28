#include <stdio.h>
#include <stdlib.h>
#include "divisors.h"

void usage(char * programName) {
  printf("\n%s NUM ARQ\n", programName);
  printf("  NUM \t\tinteiro cujo divisores serão gerados\n");
  printf("  ARQ \t\tarquivo para armazenar\n");
}

int checkParameters(int argc, char ** argv)
{
  if (argc < 3) {
    return 0;
  }
  if (atol(argv[1]) <= 0)
  {
    return 0;
  }
  return 1;
}

int main(int argc, char ** argv)
{
  FILE * file;
  if (!checkParameters(argc, argv)) {
    usage(argv[0]);
    return 1;
  }
  file = fopen(argv[2], "w");
  if (file == NULL) {
    printf("ERROR: Não foi possível abrir o arquivo \"%s\".\n", argv[2]);
    return 2;
  }
  if (generateDivisors(atol(argv[1]), file) != 0) {
    printf("ERROR: Não foi possível escrever no arquivo \"%s\".\n", argv[2]);
    return 3;
  }
  fclose(file);
  return 0;
}
