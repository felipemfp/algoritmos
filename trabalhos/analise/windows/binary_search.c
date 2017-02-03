#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define FILENAME "binary_search.csv"

int binary_search(int arr[], int start, int end, int n);

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

int main(int argc, char const *argv[]) {

  FILE * out_file;
  double executions = 1000;
  int exponent = 20;
  LARGE_INTEGER begin, end;
  LARGE_INTEGER freq;
  double ms;
  double time_sum;
  int i, j;

  out_file = fopen(FILENAME, "w");

  if (out_file == NULL){
    printf("ERROR: The file '%s' can't be opened!.\n", FILENAME);
    return 2;
  }

  fprintf(out_file, "index,exponent,time (ms)\n");

  if (argc > 1){
    exponent = atoi(argv[1]);
  }

  QueryPerformanceFrequency(&freq);

  for (i = 1; i <= exponent; i++) {

    int numbers_size = pow(2, i);
    int numbers[numbers_size];
    int number = numbers_size - 1;
    int number_index;

    time_sum = 0;

    for (j = 0; j < numbers_size; j++) {
      numbers[j] = j;
    }

    for (j = 0; j < executions; j++) {

      QueryPerformanceCounter(&begin);

      binary_search(numbers, 0, numbers_size - 1, number);

      QueryPerformanceCounter(&end);

      ms = (double) (end.QuadPart - begin.QuadPart) / freq.QuadPart * 1000;
      time_sum += ms;

    }

    fprintf(out_file, "%d,%d,%f\n", i, (int)pow(2, i), (time_sum / executions));
  }

  fclose(out_file);

  return 0;
}
