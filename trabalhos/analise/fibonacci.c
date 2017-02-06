#include "fibonacci.h"

int n_fibonacci(int n) {
  return n < 2 ? 1 : (n_fibonacci(n - 1) + n_fibonacci(n - 2));
}
