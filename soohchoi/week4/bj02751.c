#include <stdio.h>
#include <stdlib.h>

int n;
int size;
int *sorted;

void merge(int a[], int m, int middle, int n)
{
  int i = m;
  int j = middle + 1;
  int k = m;

  while (i <= middle && j <= n)
  {
    if (a[i] <= a[j])
    {
      sorted[k] = a[i];
      i++;
    }
    else
    {
      sorted[k] = a[j];
      j++;
    }
    k++;
  }
  if(i > middle)
  {
    for (int t = j; t <= n; t++)
    {
      sorted[k] = a[t];
      k++;
    }
  }
  else
  {
    for (int t = i; t <= middle; t++)
    {
      sorted[k] = a[t];
      k++;
    }
  }
  for(int t = m; t <= n; t++)
  {
    a[t] = sorted[t];
  }
}

void mergesort(int a[], int m, int n)
{
  int middle = (m + n) / 2;
  if(m < n)
  {
    mergesort(a, m, middle);
    mergesort(a, middle + 1, n);
    merge(a, m, middle, n);
  }
}

int main(void) {
  int i = 0;
  int *temp;
  
  scanf("%d", &n);
  temp = (int *)malloc(sizeof(int) * n);
  sorted = (int *)malloc(sizeof(int) * n);
  while (i < n)
  {
    scanf("%d", &temp[i]);
    i++;
  }
  mergesort(temp, 0, n - 1);
  for (i=0;i<n;i++)
  {
    printf("%d\n",temp[i]);
  }
  return 0;
}
