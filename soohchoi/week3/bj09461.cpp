#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T;
  int n;
  long long int p[101] = {};

  cin >> T;
  p[1] = 1;
  p[2] = 1;
  p[3] = 1;
  p[4] = 2;
  p[5] = 2;
  while (T > 0)
  {
    cin >> n;
    for(int i = 6; i <= n; i++)
      p[i] = p[i - 1] + p[i - 5];
    cout << p[n] << "\n";
    T--;
  }
}
