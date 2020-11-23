#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int num[10000] = {0, };
  int N, i;
  int j; 

  scanf("%d", &N);
  for(i = 0; i < N ; i++)
  {
    scanf("%d", &j);
    num[j - 1]++;
  }
  for(i = 0;i < 10000; i++)
  {
    if(num[i] != 0)
    {
      while(num[i] > 0)
      {
        printf("%d\n", i + 1);
        num[i]--;
      }
    }
  }
  return 0;
}
