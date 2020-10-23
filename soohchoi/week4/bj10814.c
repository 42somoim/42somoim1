#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int join;
  int year;
  char name[101];
} person;

int divide(person *arr, int left, int right)
{
    person pivot;
    int low = left + 1;
    int high = right;
    person temp;

    pivot = arr[left];
    while (low <= high)
    {
        while (low <= right && (pivot.year > arr[low].year || (pivot.year == arr[low].year && pivot.join > arr[low].join)))
            low++;
        while (high >= (left + 1) && (pivot.year < arr[high].year || (pivot.year == arr[high].year && pivot.join < arr[high].join)))
            high--;
        if (low <= high)
        {
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;
    return (high);
}

void quicksort(person *arr, int l, int r)
{
    int pivot;

    if (l <= r)
    {
        pivot = divide(arr, l, r);
        quicksort(arr, l, pivot -1);
        quicksort(arr, pivot + 1, r);
    }
}

int main(void) {
  int n;
  int i = 0;
  person  *ret;

  scanf("%d", &n);
  ret = (person *)malloc(sizeof(person) * n);
  while (i < n)
  {
    ret[i].join = i;
    scanf("%d %s", &ret[i].year, ret[i].name);
    i++;
  }
  quicksort(ret, 0, n - 1);
  for (i = 0 ; i < n; i++)
  {
    printf ("%d %s\n", ret[i].year, ret[i].name);
  }
}
