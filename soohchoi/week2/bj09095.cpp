#include <iostream>
#include <cmath>

using namespace std;
int sol[12];

int solution(int n)
{
  int i;
  fill_n(sol, 12, 0);
  sol[1] = 1;
  sol[2] = 2;
  sol[3] = 4;
  for (i = 4; i <= n; i++)
  {
    sol[i] = sol[i - 1] + sol[i - 2] + sol[i - 3];
  }
  return sol[n];
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T, n;

  cin >> T;
  while (T > 0)
  {
    cin >> n;
    cout << solution(n)<< "\n";
    T--;
  }
}
