#include "quick_sort.h"

void quick_sort(int a[], int start, int end) {
  int i = start;
  int j = end;
  int pivot = a[(start + end) / 2];
  int aux;

  while (i < j) {
    while (a[i] < pivot) {
      i += 1;
    }
    while (a[j] > pivot) {
      j -= 1;
    }
    if (i < j) {
      aux = a[i];
      a[i] = a[j];
      a[j] = aux;
    }
    i += 1;
    j -= 1;
  }

  if (j > start) {
    quick_sort(a, start, j);
  }

  if (i < end) {
    quick_sort(a, i, end);
  }
}
