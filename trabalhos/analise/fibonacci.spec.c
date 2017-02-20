#include <stdio.h>
#include "fibonacci.h"

#define LENGTH 3

int main(int argc, char const *argv[]) {
  // arrange
  int i;
  int values[] = { 1, 5, 10 };
  int expected[] = { 1, 5, 55 };
  int results[LENGTH];

  // act
  results[0] = n_fibonacci(values[0]);
  results[1] = n_fibonacci(values[1]);
  results[2] = n_fibonacci(values[2]);

  // assert
  for (i = 0; i < LENGTH; i++) {
    if (expected[i] != results[i]) {
      printf("Expected: %d, Received: %d", expected[i], results[i]);
      return 1;
    }
  }
  return 0;
}
