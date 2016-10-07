/*
 * Implemente uma função recursiva que seja responsável de calcular a divisão de
 * 2 números, exemplo: div(10, 2) = 5.
 */

 #include <stdio.h>

 int _div(int x, int y)
 {
   return x < y ? 0 : 1 + _div(x - y, y);
 }

 int main(void) {
   int x = 97, y = 4;
   printf("_div(%d, %d) = %d\n", x, y, _div(x, y)); // expected: _div(97, 4) = 24
   return 0;
 }
