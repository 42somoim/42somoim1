#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, K;
  long long d[201][201] = {0};

  cin >> N >> K;
  for(int i = 0; i <= N; i++)
  {
    d[1][i] = 1;
  }
  for(int k = 2; k <= K; k++)
  {
    for (int n = 0; n <= N; n++)
    {
      for(int l = 0; l <= n; l++)
      {
        d[k][n] += d[k - 1][l];
      }
      d[k][n] %= 1000000000;
    }
  }
  cout << d[K][N] << "\n";
}
