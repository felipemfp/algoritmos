#include <stdio.h>
#include "stack.h"

#define INIT       1
#define PUSH       2
#define POP        3
#define LENGTH     4
#define LIST       5
#define TO_FILE    6
#define QUIT       0

void showMenu();
int handleOption(int option);
int handleMenu();

int main(int argc, char const *argv[])
{
  return handleMenu();
}

void showMenu()
{
  printf("\t%d para iniciar uma pilha\n", INIT);
  printf("\t%d para adicionar na pilha\n", PUSH);
  printf("\t%d para remover da pilha\n", POP);
  printf("\t%d para saber o tamanho da pilha\n", LENGTH);
  printf("\t%d para listar a pilha\n", LIST);
  printf("\t%d para salvar a pilha num arquivo\n", TO_FILE);
  printf("\t%d para sair\n", QUIT);
}

int handleOption(int option)
{
  int value;
  char filename[80];
  switch (option)
  {
  case INIT:
    printf("Para iniciar uma lista, digite um valor inicial: ");
    scanf("%d", &value);
    Stack_Init(value);
    break;
  case POP:
    if (Stack_Length() > 0)
    {
      value = Stack_Pop();
      printf("// Valor removido: %d\n", value);
    }
    else
    {
      printf("// Pilha não iniciada\n");
    }
    break;
  case PUSH:
    printf("Digite o valor a ser adicionado: ");
    scanf("%d", &value);
    char result = Stack_Push(value);
    if (result == 1)
    {
      printf("// Valor adicionado\n");
    }
    else if (result == -1)
    {
      printf("// Pilha não iniciada\n");
    }
    else
    {
      printf("// Tamanho da pilha estourado\n");
    }
    break;
  case LENGTH:
    printf("// O tamanho atual é: %d\n", Stack_Length());
    break;
  case LIST:
    Stack_List();
    break;
  case TO_FILE:
    printf("Digite o nome do arquivo para salvar: ");
    scanf("%s", filename);
    if (!Stack_ToFile(filename))
    {
      printf("// Não foi possível salvar nesse arquivo\n");
    }
    break;
  }
  return 0;
}

int handleMenu()
{
  int option;
  do
  {
    showMenu();
    scanf("%d", &option);
    handleOption(option);
  } while (option != QUIT);
  return 0;
}
