#include <iostream>
#include <algorithm>

using namespace std;

int N, T;
int d[12];

int   main(void)
{
  cin >> T;

  d[1] = 1; // 1
  d[2] = 2; // 2, 1 + 1
  d[3] = 4; // 3, 1 + 2, 2 + 1, 1 + 1 + 1
  for (int i = 4; i <= 11; i++) {
    for (int j = 1; j <= 3; j++) {
      d[i] += d[i - j];
    }
  }

  while (T--) {
    cin >> N;
    cout << d[N] << endl;
  }

  return 0;
}
