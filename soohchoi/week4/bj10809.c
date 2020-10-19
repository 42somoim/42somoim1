#include <stdio.h>

int main(void) {
  char str[101];
  int i = 0;
  int alpha[26];

  for(i = 0; i < 26; i++)
  {
    alpha[i] = -1;
  }
  i = 0;
  scanf("%s", str);
  while (i < 101 && str[i] != '\0')
  {
    if (alpha[(int)str[i] - 97] == -1)
    {
      alpha[(int)str[i] - 97] = i;
    }
    i++;
  }
  for (i = 0; i < 25; i++)
  {
    printf("%d ", alpha[i]);
  }
  printf("%d", alpha[25]);
  return 0;
}
