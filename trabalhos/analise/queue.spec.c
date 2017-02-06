#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define LENGTH 5

int main(int argc, char const *argv[]) {
  // arrange
  int i;
  int expected[] = {1, 2, 3, 4, 5};
  int results[LENGTH];

  // act
  queue_enqueue(expected[0]);
  queue_enqueue(expected[1]);
  queue_enqueue(expected[2]);
  queue_enqueue(expected[3]);
  queue_enqueue(expected[4]);
  results[0] = queue_dequeue();
  results[1] = queue_dequeue();
  results[2] = queue_dequeue();
  results[3] = queue_dequeue();
  results[4] = queue_dequeue();

  // assert
  for (i = 0; i < LENGTH; i++) {
    if (expected[i] != results[i]) {
      return 1;
    }
  }
  return 0;
}
