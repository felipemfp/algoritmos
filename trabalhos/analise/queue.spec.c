#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char const *argv[]) {
  // arrange
  int i;
  int expected[] = {1, 2, 3, 4, 5};
  int result[5];

  // act
  queue_enqueue(expected[0]);
  queue_enqueue(expected[1]);
  queue_enqueue(expected[2]);
  queue_enqueue(expected[3]);
  queue_enqueue(expected[4]);
  result[0] = queue_dequeue();
  result[1] = queue_dequeue();
  result[2] = queue_dequeue();
  result[3] = queue_dequeue();
  result[4] = queue_dequeue();

  // assert
  for (i = 0; i < 5; i++) {
    if (expected[i] != result[i]) {
      return 1;
    }
  }
  return 0;
}
