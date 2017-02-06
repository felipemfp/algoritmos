#include <stdlib.h>
#include "queue.h"

void queue_enqueue(int x) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

  temp->data = x;

  if (queue_last == NULL) {
    queue_last = temp;
  }
  else {
    temp->next = queue_last;
    queue_last = temp;
  }
}

int queue_dequeue() {
  struct Node* temp_a;
  struct Node* temp_b = queue_last;
  int data;

  if (temp_b == NULL) {
    return -1;
  }

  if (temp_b->next == NULL) {
    data = temp_b->data;
    free(temp_b);
    queue_last = NULL;
  }
  else {
    temp_a = temp_b->next;
    while(temp_a->next != NULL) {
      temp_b = temp_a;
      temp_a = temp_a->next;
    }
    data = temp_a->data;
    temp_b->next = NULL;
    free(temp_a);
  }

  return data;
}

void queue_clear() {
  while (queue_last != NULL) {
    queue_dequeue();
  }
}
