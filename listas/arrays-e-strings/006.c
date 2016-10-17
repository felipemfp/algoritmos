#include <stdio.h>
#include <string.h>

char getZenitPolar(char c)
{
  switch (c)
  {
    case 'P':
      return 'Z';
    case 'O':
      return 'E';
    case 'L':
      return 'N';
    case 'A':
      return 'I';
    case 'R':
      return 'T';
    case 'Z':
      return 'P';
    case 'E':
      return 'O';
    case 'N':
      return 'L';
    case 'I':
      return 'A';
    case 'T':
      return 'R';
    case 'p':
      return 'z';
    case 'o':
      return 'e';
    case 'l':
      return 'n';
    case 'a':
      return 'i';
    case 'r':
      return 't';
    case 'z':
      return 'p';
    case 'e':
      return 'o';
    case 'n':
      return 'l';
    case 'i':
      return 'a';
    case 't':
      return 'r';
  }
  return c;
}

void encodeWithZenitPolar(char * str, char * buf)
{
  int i, len = strlen(str);
  for (i=0; i<len; i++)
  {
    buf[i] = getZenitPolar(str[i]);
  }
}

int main(void) {
  setvbuf(stdout, NULL, _IONBF, 0);
  char phrase[100], encoded[100];

  printf("Digite uma frase:");
  scanf("%[^\n]", &phrase);
  encodeWithZenitPolar(phrase, encoded);
  printf("%s\n", encoded);
  return 0;
}
