#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int arr[501];
int sum[501];
int d[501][501]; // from i to j

int   main(void)
{
  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
      if (i == 0)
        sum[i] = arr[i];
      else
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int len = 2; len <= N; len++) {
      int start, end;
      for (start = 0; (end = start + len - 1) < N; start++) {
        int ans = INT_MAX;
        for (int middle = start; middle < end; middle++) {
          ans = min(ans, d[start][middle] + d[middle + 1][end]);
        }
        d[start][end] = ans + (sum[end] - sum[start - 1]);
      }
    }
    cout << (d[0][N - 1]) << "\n";
  }

  return 0;
}
