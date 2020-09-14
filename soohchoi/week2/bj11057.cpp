#include <iostream>

using namespace std;

int solution(int n)
{
  int sol[1001][10] = {};
  int sum = 0;
  int temp = 0;

  for (int i = 0; i < 10; i++)
    sol[1][i] = 1;
  for(int i = 2; i <= n; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      for (int k = j ; k < 10; k++)
      {
        sol[i][j] = (sol[i][j] + sol[i - 1][k]) % 10007;
      }
    }
  }
  for (int i = 0; i < 10; i++)
    sum = (sum + sol[n][i]) % 10007;

  return sum;
}

int main() {
  int N;

  cin >> N;
  cout << solution(N) % 10007 << "\n";
}
