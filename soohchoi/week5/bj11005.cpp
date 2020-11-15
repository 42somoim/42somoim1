#include <iostream>
#include <algorithm>
#include <vector>
#define BASE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
using namespace std;

void solution(long long N, long long B)
{
  if (N / B > 0)
  {
    solution(N / B, B);
    cout << BASE[N % B];
  }
  else
    cout << BASE[N % B];
}

int main() {
  long long N, B;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> B;

  solution(N, B);
  cout << "\n";
  return 0;
}
