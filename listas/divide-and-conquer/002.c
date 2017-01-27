#include <stdio.h>
#include <time.h>
#include <math.h>

#define INTERATIONS    1000

int find_rec(int *a, int x, int start, int end)
{
  int mid = 0;
  if (start > end)
  {
    return 0;
  }
  else
  {
    mid = (start + end) / 2;
  }
  if (x == a[mid])
  {
    return mid;
  }
  else
  {
    if (x < a[mid])
    {
      return find_rec(a, x, start, mid - 1);
    }
    else
    {
      return find_rec(a, x, mid + 1, end);
    }
  }
}

int find_alt(int *a, int size, int x)
{
  return find_rec(a, x, 0, size - 1);
}

int find(int *a, int size, int x)
{
  int index = -1;
  int i;
  for (i = 0; i < size; i++)
  {
    if (a[i] == x)
    {
      index = 1;
      break;
    }
  }
  return index;
}

double normalize_to_millis(double arr[], int length)
{
  int i, max = 0, min = 0;
  double sum = 0.0;
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
  double avg = sum / avg_len;
  return(avg * 1000.0);
}

void interate(int value)
{
  clock_t t;
  double seconds[INTERATIONS];
  int n = value;
  int arr[n];
  int j;
  for (j = 0; j < n; j++)
  {
    arr[j] = j * 11;
  }
  printf("%d,", n);
  for (j = 0; j < INTERATIONS; j++)
  {
    t = clock();
    find(arr, n, arr[n - 1]);
    t = clock() - t;
    seconds[j] = ((double) t);
  }
  printf("%f,", normalize_to_millis(seconds, INTERATIONS));
  for (j = 0; j < INTERATIONS; j++)
  {
    t = clock();
    find_alt(arr, n, arr[n - 1]);
    t = clock() - t;
    seconds[j] = ((double) t);
  }
  printf("%f\n", normalize_to_millis(seconds, INTERATIONS));
}

int main(int argc, char const *argv[])
{
  int i, max_pow = 7;
  for (i = 1; i <= max_pow; i++) {
    interate(pow(2, i));
  }
  return 0;
}
