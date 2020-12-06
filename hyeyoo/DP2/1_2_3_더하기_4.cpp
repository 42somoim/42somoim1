#include <iostream>
#include <algorithm>

using namespace std;

int N, T;
int d[10001];

int   main(void)
{
  cin >> T;

  d[0] = 1;
  for (int j = 1; j <= 3; j++) {
    for (int i = 1; i <= 10001; i++) {
      d[i] += d[i - j];
    }
  }

  while (T--) {
    cin >> N;
    cout << d[N] << endl;
  }

  return 0;
}
