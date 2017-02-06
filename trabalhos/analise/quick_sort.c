#include "quick_sort.h"

void quick_sort(int a[], int start, int end) {
  int i, j;
  int base = start, aux;
  for (i = start + 1; i <= end; i++) {
    j = i;
    if(a[j] < a[base]) {
      aux = a[j];
      while (j > base) {
        a[j] = a[j-1];
        j--;
      }
      a[j] = aux;
      base++;
    }
  }
  if (base - 1 >= start) {
    quick_sort(a, start, base-1);
  }
  if (base + 1 <= end) {     
    quick_sort(a,base+1,end);
  }
}
