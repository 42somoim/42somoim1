#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  long long ret = 1;

  cin >> n;
  while (n > 0)
  {
    ret *= n;
    n--;
  }
  cout << ret;
}
