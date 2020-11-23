#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long a, b;
  long long n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b;
  if (a < b)
  {
    n = a;
    a = b;
    b = n;
  }
  while ((n = a % b) != 0)
  {
    a = b;
    b = n;
  }
  while (b > 0)
  {
    cout << "1";
    b--;
  }
  cout << "\n";
}
