/*
   http://br.spoj.com/problems/LOTICA/
 */

#include "stdio.h"

char getLetter(int m)
{
  char letters[5] = { 'A', 'B', 'C', 'D', 'E' };
  return letters[m];
}

int main(void)
{
  int  i, j, n, current;
  char letter;
  scanf("%d", &n);
  while (n > 0)
  {
    for (j = 0; j < n; j++)
    {
      letter = '*';
      for (i = 0; i < 5; i++)
      {
        scanf("%d", &current);
        if (current <= 127)
        {
          if (letter == '*')
          {
            letter = getLetter(i);
          }
          else
          {
            letter = '#';
          }
        }
      }
      if (letter == '#')
      {
        letter = '*';
      }
      printf("%c\n", letter);
    }
    scanf("%d", &n);
  }
  return 0;
}
