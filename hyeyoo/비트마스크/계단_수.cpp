#include <iostream>
#include <vector>

using namespace std;

// digit, len, mask
int dp[10][101][1 << 10];

int   main(void)
{
  int N;
  cin >> N;
  const int b = 1000000000;

  for (int i = 1; i < 10; i++) {
    dp[i][1][1 << i] = 1;
  }

  for (int len = 2; len <= N; len++) {
    for (int digit = 0; digit < 10; digit++) {
      for (int mask = 0; mask < (1 << 10); mask++) {
        int new_mask = mask | 1 << digit;
        int sum;
        if (digit == 0) {
          sum = dp[digit + 1][len - 1][mask];
        } else if (digit == 9) {
          sum = dp[digit - 1][len - 1][mask];
        } else {
          sum = dp[digit - 1][len - 1][mask] % b;
          sum += dp[digit + 1][len - 1][mask] % b;
          sum %= b; 
        }
        dp[digit][len][new_mask] += sum;
        dp[digit][len][new_mask] %= b;
      }
    }
  }
  long long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += (dp[i][N][(1 << 10) - 1] % b);
    sum %= b;
  }
  cout << sum << endl;
  return 0;
}
