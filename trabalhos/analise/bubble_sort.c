#include "bubble_sort.h"

void bubble_sort(int a[], int length) {
  int i, j, aux, sorting;

  do {
    sorting = 0;

    for (i = 0; i < length - 1; i++) {
      if (a[i] > a[i + 1]) {
        aux = a[i];
        a[i] = a[i+1];
        a[i+1] = aux;
        sorting = 1;
      }
    }

  } while(sorting);
}
