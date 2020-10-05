#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  int num;
  int d[100001] = {};
  
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    d[i] = i;
    for (int j = 1; j * j <= i; j++)
      d[i] = min(d[i], d[i - j * j] + 1);
  }
  cout << d[n] << "\n";
}
