#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<long long> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  for (int i = 0; i < N; i++)
  {
    long long num;
    cin >> num;

    v.push_back(num);
  }

  sort(v.begin(), v.end());
  cout << v[K - 1] << "\n";
  return 0;
}
