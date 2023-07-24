#include <stdio.h>
#define MAX_CHAR 102

int isVowel(char a)
{
  if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
  {
    return 1;
  }
  return 0;
}
int main()
{
  char txt[MAX_CHAR];
  fgets(txt, MAX_CHAR, stdin);

  for (int i = 0; txt[i] != 0; i++)
  {
    if (!isVowel(txt[i]))
    {
      printf("%c", txt[i]);
    }
    else
    {
      printf("%c", txt[i]);
      i+= 2;
      continue;
    }
  }
  return 0;
}