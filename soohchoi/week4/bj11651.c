#include <stdio.h>
#include <stdlib.h>

int divide(int *arr[], int left, int right)
{
    int pivot[2];
    int low = left + 1;
    int high = right;
    int *temp;

    pivot[0] = arr[left][0];
    pivot[1] = arr[left][1];
    while (low <= high)
    {
        while (low <= right && (pivot[1] > arr[low][1] || (pivot[1] == arr[low][1] && pivot[0]  > arr[low][0])))
            low++;
        while (high >= (left + 1) && (pivot[1] < arr[high][1] || (pivot[1] == arr[high][1] &&   pivot[0] < arr[high][0])))
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


void quicksort(int *arr[], int l, int r)
{
    int pivot;

    if (l <= r)
    {
        pivot = divide(arr, l, r);
        quicksort(arr, l, pivot -1);
        quicksort(arr, pivot + 1, r);
    }
}


int main()
{
    int **arr;
    int n;
    int i = 0;

    scanf("%d", &n);
    arr = (int **)malloc(sizeof(int *) * n);
    while (i < n)
    {
        arr[i] = (int *)malloc(sizeof(int) * 2);
        scanf("%d %d", &arr[i][0],&arr[i][1]);
        i++;
    }
    quicksort(arr, 0, n - 1);
    i = 0;
    while(i < n)
    {
        printf("%d %d\n", arr[i][0], arr[i][1]);
        i++;
    }
    return 0;
}
