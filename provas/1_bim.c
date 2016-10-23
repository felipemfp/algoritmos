#include <stdio.h>
#include <string.h>

int sumDigits(int n)
{
  /*
   * Escreva, em ANSI C, uma função que calcule a soma dos dígitos de um número
   * inteiro. Por exemplo, se a entrada for 123, a saída deverá ser 1 + 2 + 3 = 6.
   */

  int r = 0;
  while (n >= 10)
  {
    r += n % 10;
    n /= 10;
  }
  return r + n;
}

int ackermann(int m, int n)
{
  /*
   * Escreva, em ANSI C, uma função recursiva que calcule Função de Ackermann.
   * https://pt.wikipedia.org/wiki/Fun%C3%A7%C3%A3o_de_Ackermann
   */

  if (m == 0)
    return n + 1;
  if (m > 0)
    if (n == 0)
      return ackermann(m - 1, 1);
    else if (n > 0)
      return ackermann(m - 1, ackermann(m, n - 1));
  return -1;
}

int countWords(char s[])
{
  /*
   * Escreva uma função que receba uma string e conte quantas palavras tem a
   * string.
   */

  int i, len = strlen(s), howMany = 0;
  for (i = 0; i < len; i++)
  {
    while (s[i] != ' ')
    {
      i++;
      if (i >= len)
      {
        break;
      }
    }
    howMany += 1;
    while (s[i] == ' ')
    {
      i++;
      if (i >= len)
      {
        break;
      }
    }
  }
  return howMany;
}

int main(int argc, char const *argv[])
{
  int n = 123, a = 2, b = 2;
  char frase[] = "A vida num eh    bela!";
  printf("sumDigits(%d) = %d\n", n, sumDigits(n));
  printf("ackermann(%d, %d) = %d\n", a, b, ackermann(a, b));
  printf("countWords(%s) = %d\n", frase, countWords(frase));
  return 0;
}
