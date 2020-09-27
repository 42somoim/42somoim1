#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string str;
  int a[5001];
  int len;
  long d[5001] = {};

  cin >> str;
  len = str.length();
  for (int i = 1; i <= len; i++)
  {
    a[i] = str[i - 1] - '0';
  }
  if (len == 1 && str[0] == '0')
  {
    cout << 0 << "\n";
    exit(0);
  }
  d[0] = 1;
  for (int i = 1; i <= len; i++)
  {
    if (a[i] >= 1 && a[i] <= 9)
    {
      d[i] = (d[i - 1] + d[i]) % 1000000;
    }
    if (i == 1)
      continue;
    int temp = a[i] + a[i - 1] * 10;
    if (temp >= 10 && temp <= 26)
    {
      d[i] = (d[i - 2] + d[i]) % 1000000;
    }
  }
  cout << d[len] << "\n";
}
