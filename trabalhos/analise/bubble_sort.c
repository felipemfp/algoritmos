#include "bubble_sort.h"

void bubble_sort(int a[], int length) {
  int i, j, aux;

  for (i = 0; i < length - 1; i++) {
    for (j = 0; j < length - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        aux = a[j];
        a[j] = a[j+1];
        a[j+1] = aux;
      }
    }
  }
}
