#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  int x[300] = {};
  int d[300] = {};
  
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  d[0] = x[0];
  d[1] = max(x[1], x[0] + x[1]);
  d[2] = max(x[0] + x[2], x[1] + x[2]);
  for (int i = 3; i < n; i++)
  {
    d[i] = max(x[i] + d[i - 2], x[i] + x[i - 1] + d[i - 3]);
  }
  cout << d[n - 1] << "\n";
}
