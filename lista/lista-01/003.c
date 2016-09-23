#include "stdio.h"

char yearIsValid(int yy)
{
  return 1;
}

char monthIsValid(int mm)
{
  if (0 < mm && mm <= 12)
  {
    return 1;
  }
  return 0;
}

char dateIsValid(int yy, int mm, int dd)
{
  int ref[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  if (!yearIsValid(yy) || !monthIsValid(mm)) 
  {
    return 0;
  }
  if (0 < dd && dd <= ref[mm - 1] || (mm == 2 && yy % 4 == 0 && dd == 29))
  {
    return 1;
  }
  return 0;
}

int main(void) {
  setvbuf(stdout, NULL, _IONBF, 0);

  int yy, mm, dd;
  
  printf("Digite o ano, mês e dia: ");
  scanf("%d %d %d", &yy, &mm, &dd);
  
  if (dateIsValid(yy, mm, dd))
  {
    printf("Data válida!\n");
  }
  else
  {
    printf("Data inválida! :(\n");
  }

  return 0;
    
}