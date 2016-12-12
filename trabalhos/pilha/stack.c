#include <stdio.h>
#include "stack.h"

void Stack_Init(int initialValue)
{
  struct Node temp = { initialValue, NULL };
  Stack_nodes[0] = temp;
  Stack_lastOne = &Stack_nodes[0];
  Stack_length = 1;
}

int Stack_Length()
{
  return Stack_length;
}

void Stack_List()
{
  if (Stack_length == 0)
  {
    printf("// PILHA VAZIA\n");
  }
  struct Node * node = Stack_lastOne;
  printf("// PILHA (%d elemento%s)\n", Stack_length, Stack_length > 1 ? "s" : "");
  printf("---------\n");
  printf("| %5d |\n", node->value);
  while (node->next)
  {
    printf("---------\n");
    node = node->next;
    printf("| %5d |\n", node->value);
  }
  printf("---------\n");
}

int Stack_Pop()
{
  if (Stack_length == 0) {
      return 0;
  }
  int value = Stack_lastOne->value;
  Stack_lastOne = Stack_lastOne->next;
  Stack_length -= 1;
  return value;
}

int Stack_Push(int value)
{
  if (Stack_lastOne == NULL) {
    return -1;
  }
  if (Stack_length == STACK_SIZE) {
    return 0;
  }
  struct Node temp = { value, Stack_lastOne };
  Stack_nodes[Stack_length] = temp;
  Stack_lastOne = &Stack_nodes[Stack_length];
  Stack_length += 1;
  return 1;
}

int Stack_ToFile(const char filename[])
{
  FILE * destFile = fopen(filename, "w+");
  if (destFile != NULL && Stack_length > 0)
  {
    struct Node * node = Stack_lastOne;
    fprintf(destFile, "// PILHA (%d elemento%s)\n", Stack_length, Stack_length > 1 ? "s" : "");
    fprintf(destFile, "---------\n");
    fprintf(destFile, "| %5d |\n", node->value);
    while (node->next)
    {
      fprintf(destFile, "---------\n");
      node = node->next;
      fprintf(destFile, "| %5d |\n", node->value);
    }
    fprintf(destFile, "---------\n");
    fclose(destFile);
  }
  else
  {
    return 0;
  }
  return 1;
}
