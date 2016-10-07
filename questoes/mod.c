/*
 * Implemente uma função recursiva que seja responsável de calcular o MOD de
 * 2 números, exemplo: mod(7, 4) = 3.
 */

 #include <stdio.h>

 int mod(int x, int y)
 {
   return x < y ? x : mod(x - y, y);
 }

 int main(void) {
   int x = 97, y = 4;
   printf("mod(%d, %d) = %d\n", x, y, mod(x, y)); // expected: mod(97, 4) = 1
   return 0;
 }
