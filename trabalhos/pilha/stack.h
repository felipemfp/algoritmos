#ifndef STACK_H_
#define STACK_H_

#define STACK_SIZE 50

struct Node
{
  int value;
  struct Node * next;
};

struct Node Stack_nodes[STACK_SIZE];
struct Node * Stack_lastOne;
unsigned int  Stack_length;

void Stack_Init(int initialValue);
int Stack_Length();
void Stack_List();
int Stack_Pop();
int Stack_Push(int value);
int Stack_ToFile(const char filename[]);

#endif
