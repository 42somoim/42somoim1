#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  int m;
  int x[100000] = {};
  int d[100000] = {};
  
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  m = x[0];
  d[0] = x[0];
  for (int i = 1; i < n; i++)
  {
    d[i] = max(x[i], d[i - 1] + x[i]);
    m = max(m, d[i]);
  }
  cout << m << "\n";
}
