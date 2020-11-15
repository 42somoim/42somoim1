#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void result(int flag, char num)
{
  int N = num - '0';
  int temp = N;
  int len = 0;
  int i = 0;
  char ret[4];

  ret[3] = '\0';
  if (temp != 0)
  {
    while (temp != 0)
    {
      temp /= 2;
      len++;
    }
  }
  else
  {
    len = 1;
  }
  if (flag == 1 && len < 3)
  {
    if (len == 2)
    {
      ret[0] = N / 2 + '0';
      ret[1] = N % 2 + '0';
      ret[2] = '\0';
    }
    else if (len == 1)
    {
      ret[0] = N % 2 + '0';
      ret[1] = '\0';
      ret[2] = '\0';
    }
    printf("%s", ret);
    return ;
  }
  else
  {
    ret[0] = N / 4 + '0';
    ret[1] = (N % 4) / 2 + '0';
    ret[2] = N % 2 + '0';
    printf("%s", ret);
    return ;
  }
}

int main(void) {
  char N[333334];
  int len;
  int i = 0;
  int flag = 1;

  scanf("%s", N);
  len = strlen(N);
  while (len > 0)
  {
    result(flag, N[i]);
    flag = 0;
    len--;
    i++;
  }
  return 0;
}
