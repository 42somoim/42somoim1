#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[1000];
  int up[1000];
  int down[1000];
  int ans = 0;
  int N;

  cin >> N;
  for(int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  for(int i = 0; i < N; i++)
  {
    up[i] = 1;
    for(int j = 0; j < i; j++)
    {
      if (a[i] > a[j])
      {
        up[i] = max(up[i], up[j] + 1);
      }
    }
  }
  for(int i = N - 1; i >= 0; i--)
  {
    down[i] = 1;
    for(int j = N - 1; j > i; j--)
    {
      if (a[i] > a[j])
      {
        down[i] = max(down[i], down[j] + 1);
      }
    }
  }
  for (int i = 0; i < N; i++)
  {  
    if (ans < (up[i] + down[i] - 1))
    {
      ans = up[i] + down[i] - 1;
    }
  }
  cout << ans << "\n";
}
