#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int a, b;
  int m;
  long long p = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> ret;
  int k;
  int i;

  cin >> a >> b >> m;
  while (m > 0)
  {
    cin >> k;
    p = p * a + k;
    m--;
  }
  while (p > 0)
  {
    ret.push_back(p % b);
    p /= b;
  }
  i = ret.size() - 1;
  while (i > 0)
  {
    cout << ret[i] << " ";
    i--;
  }
  cout << ret[0];
}
