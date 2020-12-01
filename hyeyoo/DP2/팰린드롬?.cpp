#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool d[2001][2001];
int arr[2001];

int   main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  int ans = 1;
  // len = 1
  for (int i = 0; i < N; i++) {
    d[i][i] = true;
  }
  // len = 2
  for (int i =  0;i < N - 1; i++) {
    d[i][i+1] = (arr[i] == arr[i + 1]);
    if (d[i][i+1])
      ans = max(ans, 2);
  }
  for (int len = 3; len <= N; len++) {
    for (int i = 0; i < N - len + 1; i++) {
      int j = i + len - 1;
      if (!d[i + 1][j - 1])
        d[i][j] = false;
      else
        d[i][j] = (arr[i] == arr[j]);
      if (d[i][j])
        ans = max(ans, len);
    }
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int start, end;
    cin >> start >> end;
    cout << d[start - 1][end - 1] << '\n';
  }

  return 0;
}
