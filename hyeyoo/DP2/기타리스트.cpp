#include <iostream>

using namespace std;

int N, S, M;
int V[101];
      //곡 volume
bool dp[101][1001];

int   main(void)
{
  cin >> N >> S >> M;
  for (int i = 1; i <= N; i++)
    cin >> V[i];
  
  dp[0][S] = true;
  for (int i = 1; i <= N; i++) {
    for (int volume = 0; volume <= M; volume++) {
      if (dp[i - 1][volume] == false)
        continue;

      //+V[i]로 가는 경우
      if (volume + V[i] <= M) {
        dp[i][volume + V[i]] = true;
      }
      //-V[i]로 가는 경우
      if (volume - V[i] >= 0) {
        dp[i][volume - V[i]] = true;
      }
    }
  }

  int ans = -1;
  for (int volume = 0; volume <= M; volume++) {
    if (dp[N][volume])
      ans = volume;
  }
  cout << ans << endl;
  return 0;
}
