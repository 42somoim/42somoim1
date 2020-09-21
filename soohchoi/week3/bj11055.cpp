#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  int ret = 0;
  int x[1000] = {};
  int d[1000] = {};
  
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  for (int i = 0; i < n; i++)
  {
    d[i] = x[i];
    for (int j = 0; j < i; j++)
    {
      if(x[i] > x[j])
        d[i] = max(d[i], d[j] + x[i]);
    }
    ret = max(ret, d[i]);
  }

  cout << ret << "\n";
}
