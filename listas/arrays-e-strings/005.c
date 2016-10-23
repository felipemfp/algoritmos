#include <stdio.h>
#include <string.h>

char isLetter(char c)
{
  if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
  {
    return 1;
  }
  return 0;
}

char isPalindrome(char * str)
{
  int i, j, len = strlen(str);
  for (i = 0, j = len - 1; i < len; i++, j--)
  {
    while (!isLetter(str[i]))
    {
      i++;
      if (len <= i)
      {
        return 0;
      }
    }
    while (!isLetter(str[j]))
    {
      j--;
      if (j <= 0)
      {
        return 0;
      }
    }
    if (str[i] >= 97)
    {
      str[i] = str[i] - 'a' + 'A';
    }
    if (str[j] >= 97)
    {
      str[j] = str[j] - 'a' + 'A';
    }
    if (str[i] != str[j])
    {
      return 0;
    }
    if (i >= j)
    {
      break;
    }
  }
  return 1;
}

int main(void)
{
  setvbuf(stdout, NULL, _IONBF, 0);
  char phrase[100];

  printf("Digite uma frase:");
  scanf("%[^\n]", &phrase);

  if (isPalindrome(phrase))
  {
    printf("É palindromo.\n");
  }
  else
  {
    printf("Não é palindromo.\n");
  }

  return 0;
}
