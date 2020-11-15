#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  long long B, ret = 0;
  int temp;
  string N;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> B;

  for (int i = 0; i < N.length(); i++)
  {
    if (N[i] >= 'A' && N[i] <= 'Z')
      temp = N[i] - 'A' + 10;
    else
      temp = N[i] - '0';
    ret = ret * B + temp;
  }
  cout << ret << "\n";
  return 0;
}
