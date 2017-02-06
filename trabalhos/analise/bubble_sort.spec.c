#include <stdio.h>
#include "bubble_sort.h"

#define LENGTH 6

int main(int argc, char const *argv[]) {
  // arrange
  int i;
  int arr[] = { 10, 5, 8, 9, 2, 1 };
  int expected[] = { 1, 2, 5, 8, 9, 10};
  int results[] = { 10, 5, 8, 9, 2, 1 };

  // act
  bubble_sort(results, LENGTH);

  // assert
  for (i = 0; i < LENGTH; i++) {
    if (expected[i] != results[i]) {
      return 1;
    }
  }
  return 0;
}
