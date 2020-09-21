#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  int w[10001] = {};
  int d[10001] = {};
  
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 1; i < 3 && i <= n; i++)
  {
    if (i == 1)
      d[i] = w[i];
    else
      d[i] = w[i] + w[i - 1];
  }
  for (int i = 3; i <= n; i++)
  {
    d[i] = max(w[i] + w[i - 1] + d[i - 3], w[i] + d[i -2]);
    d[i] = max(d[i], d[i - 1]);
  }
  cout << d[n] << "\n";
}
