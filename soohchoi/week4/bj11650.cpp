#include <iostream>
using namespace std;

void quick_sort(int **data, int start, int end)
{
  int pivot = start;
  int i = pivot + 1;
  int j = end;
  int *temp;

  if (start >= end)
    return ;
  while (i <= j)
  {
    while (i <= end && data[i][0] <= data[pivot][0])
    {
      if (data[i][0] == data[pivot][0] && data[i][1] > data[pivot][1])
        break;
      i++;
    }
    while (j > start && data[j][0] >= data[pivot][0])
    {
      if (data[j][0] == data[pivot][0] && data[j][1] < data[pivot][1])
        break;
      j--;
    }
    if (i > j)
    {
      temp = data[j];
      data[j] = data[pivot];
      data[pivot] = temp;
    }
    else
    {
      temp = data[i];
      data[i] = data[j];
      data[j] = temp;
    }
  }
  quick_sort(data, start, j - 1);
  quick_sort(data, j + 1, end);
}

int main() {
  int N;
  int **a;

  a = new int*[100000];

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    a[i] = new int[2];
    cin >> a[i][0] >> a[i][1];
  }
  
  quick_sort(a, 0, N - 1);

  for (int i = 0; i < N; i++)
  {
    cout << a[i][0] << " " << a[i][1] << "\n";
  }

  return 0;
}
