#include <stdio.h>
#include "binary_search.h"

int binary_search(int arr[], int start, int end, int n) {
  int i = (start + end) / 2;
  if (arr[i] == n) {
    return i;
  }
  if (start >= end) {
    return -1;
  }
  if (n < arr[i]) {
    return binary_search(arr, start, i - 1, n);
  }
  return binary_search(arr, i + 1, end, n);
}
