#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N,K;
  int *num;
  int i;
  int temp;
  int count;

  scanf("%d %d", &N, &K);
  num = (int *)malloc(sizeof(int) * N);
  for (i = 0;i<N;i++)
  {
    num[i] = 1;
  }
  temp = N;
  printf("<");
  while (temp > 1)
  {
    count = 0;
    while (count < K)
    {
      if (i == N)
      {
        i -= N;
      }
      if (num[i] != -1)
      {
        count++;
      }
      if (count == K)
      {
        break ;
      }
      i++;
    }
    num[i] = -1;
    printf("%d, ", i+1);
    temp--;
  }
  if (temp == 1)
  {
    count = 0;
    while (count < K)
    {
      if (i == N)
      {
        i -= N;
      }
      if (num[i] != -1)
      {
        count++;
      }
      if (count == K)
      {
        break ;
      }
      i++;
    }
    num[i] = -1;
    printf("%d>", i+1);
    temp--;
  }
  return 0;
}
