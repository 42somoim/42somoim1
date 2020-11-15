#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void sol(long long N)
{
  int i;
  if (N == 0)
    return ;
  i = N % (-2);
  if (i == -1)
  {
    i = 1;
    N--;
  }
  sol(N / (-2));
  cout << i;
  return ;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long N;

  cin >> N;
  if (N == 0)
  {
    cout << "0\n";
    return 0;
  }
  sol(N);
  cout << "\n";
  return 0;
}
