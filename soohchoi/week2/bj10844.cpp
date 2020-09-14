#include <iostream>

using namespace std;

int solution(int n)
{
  int sol[101][10] = {};
  int sum = 0;

  for (int i = 0; i < 10; i++)
    sol[1][i] = 1;
  for(int i = 2; i <= n; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (j == 0)
        sol[i][0] = sol[i - 1][1];
      else if (j == 9)
        sol[i][9] = sol[i - 1][8];
      else
        sol[i][j] = (sol[i - 1][j - 1] + sol[i - 1][j + 1]) % 1000000000;
    }
  }
  for (int i = 1; i < 10; i++)
    sum = (sum + sol[n][i]) % 1000000000;

  return sum;
}

int main() {
  int N;

  cin >> N;
  cout << solution(N) % 1000000000 << "\n";
}
