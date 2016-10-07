/*
 * Escreva um programa que calcule a some de todos os elementos de um array
 * de forma recursiva.
 */

 #include <stdio.h>

 int recursive_sum(int * arr, int length)
 {
   if (length == 0)
   {
     return 0;
   }
   if (length == 1)
   {
     return arr[0];
   }
   return arr[length - 1] + recursive_sum(arr, length - 1);
 }

 int main(void) {
   int myArr[5] = { 78, 254, 56, 452, 4562 };

   printf("%d\n", recursive_sum(myArr, 5)); // expected: 5402
   return 0;
 }
