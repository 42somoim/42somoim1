#include <iostream>
#include <algorithm>

using namespace std;
int sol[1001];

int solution(int X)
{
  int i;
  fill_n(sol, 1001, 0);
  sol[1] = 1;
  sol[2] = 2;
  for (i = 3; i <= X; i++)
  {
    sol[i] = (sol[i - 1] + sol[i - 2]) % 10007;
  }
  return sol[X];
}

int main() {
  int X;

  cin >> X;
  cout << solution(X) % 10007 << "\n";
}
