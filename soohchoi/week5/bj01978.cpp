#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int is_prime(int n)
{
  long long i = 2;
  
  if (n <= 1)
    return (0);
  while (i * i <= n)
  {
    if (n % i == 0)
      return (0);
    i++;
  }
  return (1);
}


int main() {
  int n, j, count = 0;
  vector<int> p;

  cin >> n;
  while (n > 0)
  {
    cin >> j;
    p.push_back(j);
    n--;
  }
  for (int i = 0; i < p.size(); i++)
  {
    count += is_prime(p[i]);
  }
  cout << count;
}
