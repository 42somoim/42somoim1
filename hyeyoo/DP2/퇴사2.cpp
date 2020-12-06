#include <iostream>
#include <algorithm>

using namespace std;

int N;
int t[1500002];
int p[1500002];
int d[1500002];

int   main(void)
{
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> t[i] >> p[i];
  }

  for (int i = 1; i <= N; i++) {
    d[i + t[i]] = max(d[i] + p[i], d[i + t[i]]);
    d[i + 1] = max(d[i], d[i + 1]); // not doing
  }
  cout << d[N + 1] << endl;
  return 0;
}
