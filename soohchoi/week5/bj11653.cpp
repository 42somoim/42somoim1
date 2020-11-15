#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  int k = 2;

  cin >> n;
  if (n == 1)
    return 0;
  while (k <= n)
  {
    if (n % k == 0)
    {
      cout << k << "\n";
      n /= k;
    }
    else
    {
      k++;
    }
  }
}
