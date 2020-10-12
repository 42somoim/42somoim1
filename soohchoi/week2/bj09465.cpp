#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T;
  int n;
  int x[2][100001];
  int d[2][100001];
  
  cin >> T;
  while (T > 0)
  {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> x[0][i];
    for (int i = 1; i <= n; i++)
      cin >> x[1][i];
    d[0][0] = 0;
    d[1][0] = 0;
  	d[0][1] = x[0][1];
  	d[1][1] = x[1][1];
  	for (int i = 2;i <= n;i++)
  	{
    	d[0][i] = max(d[1][i - 1], d[1][i - 2]) + x[0][i];
    	d[1][i] = max(d[0][i - 1], d[0][i - 2]) + x[1][i];
  	}
    cout << max(d[0][n], d[1][n]) << "\n";
    T--;
  }
}
