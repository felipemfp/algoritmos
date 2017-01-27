#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define INTERATIONS    1000

double pow_rec(double a, int n)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return a;
  double p = 1;
  if (n % 2 == 1)
  {
    p = a;
    n = n - 1;
  }
  double r = pow_rec(a, n / 2);
  return p * r * r;
}

double pow_with_loop(double a, int n)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return a;
  int i;
  double r = a;
  for (i = 1; i < n; i++) {
    r *= r;
  }
  return r;
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

void interate(int value, int n)
{
  clock_t t;
  double seconds[INTERATIONS];
  int j;

  printf("%d,", n);

  for (j = 0; j < INTERATIONS; j++)
  {
    t = clock();
    pow_with_loop(value, n);
    t = clock() - t;
    seconds[j] = ((double) t);
  }
  printf("%f,", normalize_to_millis(seconds, INTERATIONS));

  for (j = 0; j < INTERATIONS; j++)
  {
    t = clock();
    pow_rec(value, n);
    t = clock() - t;
    seconds[j] = ((double) t);
  }
  printf("%f\n", normalize_to_millis(seconds, INTERATIONS));
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  int value = rand();
  int max_pow = 7;
  int i;
  for (i = 1; i <= max_pow; i++) {
    interate(value, pow(2, i));
  }
  return 0;
}
