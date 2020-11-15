#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  int ret = 0;

  cin >> n;
  while (n > 4)
  {
    ret += n / 5;
    n /= 5;
  }
  cout << ret;

}
