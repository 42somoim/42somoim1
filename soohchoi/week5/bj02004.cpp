#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, m, temp = 0;
  int ret_5 = 0, ret_2 = 0;

  cin >> n >> m;
  if (n == m || m == 0)
  {
    cout << 0 << "\n";
    return 0;
  }
  temp = n;
  while (n > 4)
  {
    ret_5 += n / 5;
    n /= 5;
  }
  n = temp;
  while (n > 1)
  {
    ret_2 += n / 2;
    n /= 2;
  }
  n = temp;
  temp = m;
  while (m > 4)
  {
    ret_5 -= m / 5;
    m /= 5;
  }
  m = temp;
  while (m > 1)
  {
    ret_2 -= m/2;
    m /= 2;
  }
  m = temp;
  temp = n - m;
  while(temp > 4)
  {
    ret_5 -= temp / 5;
    temp /= 5;
  }
  temp = n -m;
  while (temp > 1)
  {
    ret_2 -= temp / 2;
    temp /= 2;
  }
  cout << min(ret_5, ret_2);

}
