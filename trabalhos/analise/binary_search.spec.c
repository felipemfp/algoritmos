#include <stdio.h>
#include "binary_search.h"

int main(int argc, char const *argv[]) {
  // arrange
  int i;
  int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int expected[] = { 0, 9, 6 };
  int result[3];

  // act
  result[0] = binary_search(arr, 0, 10, 0);
  result[1] = binary_search(arr, 0, 10, 9);
  result[2] = binary_search(arr, 0, 10, 6);

  // assert
  for (i = 0; i < 5; i++) {
    if (expected[i] != result[i]) {
      return 1;
    }
  }
  return 0;
}
