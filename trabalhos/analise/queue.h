#ifndef QUEUE_H

#define QUEUE_H

struct Node {
  int data;
  struct Node * next;
};

struct Node * queue_first;
struct Node * queue_last;
void queue_enqueue(int x);
int queue_dequeue();

#endif
