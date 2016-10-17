#include <stdio.h>
#include <string.h>

int howManyWords(char* str)
{
	int i, len = strlen(str), howMany = 0;
	for (i=0; i<len; i++)
	{
		while (str[i] != ' ')
		{
			i++;
			if (i >= len)
			{
				break;
			}
		}
		howMany += 1;
		while (str[i] == ' ')
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

int main(void) {
  char phrase[100];

  printf("Digite uma frase:");
  scanf("%[^\n]", &phrase);

  printf("%d\n", howManyWords(phrase));
  return 0;
}
