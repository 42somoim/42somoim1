#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int card[1001];
  int d[1001] = {};
  int ret = 0;
  int N;

  cin >> N;
  for(int i = 1; i <= N; i++)
  {
    cin >> card[i];
  }
  card[0] = 0;
  d[0] = 0;
  d[1] = card[1];
  for(int i = 2; i <= N; i++)
  {
    d[i] = card[i];
    for(int j = 1; j < i; j++)
    {
      d[i] = max(d[i], d[i - j] + card[j]);
    }
  }
  cout << d[N] << "\n";
}
