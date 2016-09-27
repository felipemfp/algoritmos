/*
   http://br.spoj.com/problems/VARETAS/
 */

#include "stdio.h"

int main(void)
{
  int j, n;
  scanf("%d", &n);
  while (n > 0)
  {
    int len[n], qt[n], rets = 0, i = -1;
    for (j = 0; j < n; j++)
    {
      scanf("%d %d", &len[j], &qt[j]);
      while (qt[j] >= 4)
      {
        rets++;
        qt[j] -= 4;
      }

      if (qt[j] >= 2)
      {
        if (i > -1)
        {
          rets++;
          qt[j] -= 2;
          qt[i] -= 2;
          i = -1;
        }
        else
        {
          i = j;
        }
      }
    }
    printf("%d\n", rets);
    scanf("%d", &n);
  }
  return 0;
}
