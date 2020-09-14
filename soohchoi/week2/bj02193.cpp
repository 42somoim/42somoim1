#include <iostream>

using namespace std;

long long solution(int n)
{
  long long sol[91] = {};

  sol[1] = 1;
  sol[2] = 1;
  for (int i = 3; i <= n; i++)
  {
    sol[i] = sol[i - 1] + sol [i - 2];
  }
  return sol[n];
}

int main() {
  int N;

  cin >> N;
  cout << solution(N) << "\n";
}
