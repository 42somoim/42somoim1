#include <iostream>
#include <algorithm>

using namespace std;

int cost_matrix[20][20];
int dp[20][100000];
const int INF = 100000000;
// current_city, visited_mask
int N;

int   solve(int start_city, int current_city, int mask) {
  // memoization
  if (dp[current_city][mask] != INF) {
    return dp[current_city][mask];
  }
  // visited all cities
  if (mask == (1 << N) - 1) {
    return (cost_matrix[current_city][start_city] > 0)
      ? cost_matrix[current_city][start_city] : INF;
  }

  for (int next_city = 0; next_city < N; next_city++) {
    /* not visited , and can visit*/
    if (!(mask & (1 << next_city)) && 
          cost_matrix[current_city][next_city] > 0) {
      int new_mask = mask | (1 << next_city);
      // cost left to visit all cities
      dp[current_city][mask] = min(dp[current_city][mask],
        solve(start_city, next_city, new_mask) 
        + cost_matrix[current_city][next_city]);
    }
  }
  return dp[current_city][mask];
}

int   main(void)
{
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> cost_matrix[i][j];
    }
  }

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 100000; j++) {
      dp[i][j] = INF;
    }
  }

  cout << solve(0, 0, 1 << 0) << endl;

  return 0;
}
