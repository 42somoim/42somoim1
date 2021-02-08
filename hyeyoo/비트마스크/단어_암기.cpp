#include <iostream>
#include <string>

using namespace std;

int N, M;
string words[10001];
int query[10001];

int   solve(int flag) {
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if ((query[i] & flag) == query[i])
      ans++;
  }
  return ans;
}

void   forget(int *flag, char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    return ;
  else
    (*flag) = (*flag) & ~(1 << (c-'a'));
}

void   remember(int *flag, char c) {
  *flag = *flag | (1 << (c-'a'));
}

int   main(void)
{
  int flag = ~0;
  cin >> N >> M;

  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  for (int i = 0; i < N; i++) {
    cin >> words[i];
    for (int j = 0; j < words[i].size(); j++) {
      query[i] |= (1 << (words[i][j] - 'a'));
    }
  }

  for (int i = 0; i < M; i++) {
    int cmd;
    char c;
    cin >> cmd;
    cin >> c;
    if (cmd == 1) {
      forget(&flag, c);
    } else if (cmd == 2) {
      remember(&flag, c);
    }
    cout << solve(flag) << '\n';
  }

  return 0;
}
