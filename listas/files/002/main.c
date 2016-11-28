#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(char * programName) {
  printf("\n%s CEP ARQ\n", programName);
  printf("  CEP \t\tcep para buscar\n");
  printf("  ARQ \t\tarquivo com dados\n");
}

int checkParameters(int argc, char ** argv)
{
  if (argc < 3) {
    return 0;
  }
  return 1;
}

int checkString(char a[], char b[])
{
  return strcmp(a, b) == 0;
}

int main(int argc, char ** argv)
{
  FILE * file;
  char buffer[400];
  char cep[10];
  char rua[390];
  if (!checkParameters(argc, argv)) {
    usage(argv[0]);
    return 1;
  }
  file = fopen(argv[2], "r");
  if (file == NULL) {
    printf("ERROR: Não foi possível abrir o arquivo \"%s\".\n", argv[2]);
    return 2;
  }
  while (fgets(buffer, 400, file) != NULL) {
    sscanf(buffer, "%[0-9-]:%[A-Za-z0-9 ,/]", cep, rua);
    if (checkString(argv[1], cep)) {
      printf("%s\n", rua);
      fclose(file);
      return 0;
    }
  }
  fclose(file);
  printf("Não foi encontrado nenhum endereço para o CEP \"%s\".\n", argv[1]);
  return 0;
}
