#include <stdlib.h>
#include "queue.h"

void queue_enqueue(int x) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

  temp->data = x;
  temp->next = NULL;

  if (queue_first == NULL && queue_last == NULL) {
    queue_first = queue_last = temp;
  }

  queue_last->next = temp;
  queue_last = temp;
}

int queue_dequeue() {
  struct Node* temp = queue_first;

  if (queue_first == queue_last) {
    queue_first = queue_last = NULL;
  }
  else {
    queue_first = queue_first->next;
  }

  int data = temp->data;
  free(temp);
  return data;
}
