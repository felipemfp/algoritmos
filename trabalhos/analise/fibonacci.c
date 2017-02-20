#include "fibonacci.h"

int n_fibonacci(int n) {
  if (n == 0) return 0;
  return n < 2 ? 1 : (n_fibonacci(n - 1) + n_fibonacci(n - 2));
}
