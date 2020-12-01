#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int bag[101];
int weight[101];
int value[101];
int d[101][100001];

int   main(void)
{
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    cin >> weight[i] >> value[i];
  }

  int ans = 0;
  for (int i = 1;i <= N; i++) {
    for (int w = 0; w <= K; w++) {
      if (w - weight[i] >= 0) {
        // 가방에 담을 수 있는 경우
        d[i][w] = max(d[i - 1][w], d[i - 1][w - weight[i]] + value[i]);
      } else {
        // 가방에 담을 수 없는 경우
        d[i][w] = d[i - 1][w];
     }
     ans = max(ans, d[i][w]);
    }
  }

  cout << ans << endl;

  return 0;
}
