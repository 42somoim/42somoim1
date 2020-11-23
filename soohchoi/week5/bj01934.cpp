#include <iostream>
using namespace std;

int main() {
  int a, b, lcm;
  int T, n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;
  while (T > 0)
  {
    cin >> a >> b;
    lcm = a * b;
    if (a < b)
    {
      int temp = a;
      a = b;
      b = temp;
    }
    while ((n = a % b) != 0)
    {
      a = b;
      b = n;
    }
    cout << lcm / b << "\n";
    T--;
  }
}
