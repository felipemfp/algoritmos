#include <stdio.h>
#include "binary_search.h"

#define LENGTH 3

int main(int argc, char const *argv[]) {
  // arrange
  int i;
  int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int expected[] = { 0, 9, 6 };
  int results[LENGTH];

  // act
  results[0] = binary_search(arr, 0, 10, 0);
  results[1] = binary_search(arr, 0, 10, 9);
  results[2] = binary_search(arr, 0, 10, 6);

  // assert
  for (i = 0; i < LENGTH; i++) {
    if (expected[i] != results[i]) {
      return 1;
    }
  }
  return 0;
}
