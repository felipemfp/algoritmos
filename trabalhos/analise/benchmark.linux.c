#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "queue.h"
#include "binary_search.h"
#include "quick_sort.h"
#include "bubble_sort.h"
#include "fibonacci.h"

#define INTERATIONS    100

long double normalize_to_millis(long double arr[], int length)
{
  int i, max = 0, min = 0;
  long double sum = 0.0;
  if (length == 1) {
    return (arr[0] / CLOCKS_PER_SEC) * 1000.0;
  }
  for (i = 0; i < length - 2; i++)
  {
    if (arr[i] > arr[max])
    {
      max = i;
    }
    else if (arr[i] < arr[min])
    {
      min = i;
    }
  }
  for (i = 0; i < length; i++)
  {
    if (i == max || i == min)
    {
      continue;
    }
    sum += arr[i] / CLOCKS_PER_SEC;
  }
  int avg_len = length - (max != min ? 2 : 1);
  long double avg = sum / avg_len;
  return(avg * 1000.0);
}

void print_benchmark(int n, long double marks[], int length) {
  printf("%Lf\n", normalize_to_millis(marks, length));
}

void benchmark_enqueue(int n) {
  int i, j;
  clock_t benchmark_clock;
  long double marks[INTERATIONS];
  for (j = 0; j < n; j++) {
    queue_enqueue(j);
  }
  for (i = 0; i < INTERATIONS; i++) {
    benchmark_clock = clock();
    queue_enqueue(1);
    benchmark_clock = clock() - benchmark_clock;
    marks[i] = ((long double) benchmark_clock);
    queue_dequeue();
  }
  print_benchmark(n, marks, INTERATIONS);
}

void benchmark_dequeue(int n) {
  int i, j;
  clock_t benchmark_clock;
  long double marks[INTERATIONS];
  for (j = 0; j < n; j++) {
    queue_enqueue(j);
  }
  for (i = 0; i < INTERATIONS; i++) {
    benchmark_clock = clock();
    queue_dequeue();
    benchmark_clock = clock() - benchmark_clock;
    marks[i] = ((long double) benchmark_clock);
    queue_enqueue(n - 1);
  }
  print_benchmark(n, marks, INTERATIONS);
}

void benchmark_binary_search(int n) {
  int i, j;
  clock_t benchmark_clock;
  long double marks[INTERATIONS];
  int arr[n];
  for (j = 0; j < n; j++) {
    arr[j] = j;
  }
  for (i = 0; i < INTERATIONS; i++) {
    benchmark_clock = clock();
    binary_search(arr, 0, n - 1, n * 2);
    benchmark_clock = clock() - benchmark_clock;
    marks[i] = ((long double) benchmark_clock);
  }
  print_benchmark(n, marks, INTERATIONS);
}

void benchmark_quick_sort(int n) {
  int i, j;
  clock_t benchmark_clock;
  long double marks[INTERATIONS];
  int arr[n];
  for (i = 0; i < INTERATIONS; i++) {
    for (j = 0; j < n; j++) {
      arr[j] = n - j;
    }
    benchmark_clock = clock();
    quick_sort(arr, 0, n - 1);
    benchmark_clock = clock() - benchmark_clock;
    marks[i] = ((long double) benchmark_clock);
  }
  print_benchmark(n, marks, INTERATIONS);
}

void benchmark_bubble_sort(int n) {
  int i, j;
  clock_t benchmark_clock;
  long double marks[INTERATIONS];
  int arr[n];
  for (i = 0; i < INTERATIONS; i++) {
    for (j = 0; j < n; j++) {
      arr[j] = n - j;
    }
    benchmark_clock = clock();
    bubble_sort(arr, n);
    benchmark_clock = clock() - benchmark_clock;
    marks[i] = ((long double) benchmark_clock);
  }
  print_benchmark(n, marks, INTERATIONS);
}

void benchmark_fibonacci(int n) {
  int i;
  clock_t benchmark_clock;
  long double marks[INTERATIONS];
  int arr[n];
  for (i = 0; i < INTERATIONS; i++) {
    benchmark_clock = clock();
    n_fibonacci(n);
    benchmark_clock = clock() - benchmark_clock;
    marks[i] = ((long double) benchmark_clock);
  }
  print_benchmark(n, marks, INTERATIONS);
}

int main(int argc, char const *argv[]) {
  int c = atoi(argv[1]), n = atoi(argv[2]), m = atoi(argv[3]);
  for (n; n <= m; n++) {
    int k = pow(2, n);
    printf("2^%d,", n);
    switch (c) {
    case 1:
      benchmark_enqueue(k);
      break;
    case 2:
      benchmark_binary_search(k);
      break;
    case 3:
      benchmark_dequeue(k);
      break;
    case 4:
      benchmark_quick_sort(k);
      break;
    case 5:
      benchmark_bubble_sort(k);
      break;
    case 6:
      benchmark_fibonacci(k);
      break;
    default:
      return 1;
    }
  }
  return 0;
}
