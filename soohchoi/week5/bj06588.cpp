#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int is_prime(int n)
{
  long long i = 2;
  while (i * i <= n)
  {
    if (n % i == 0)
      return (0);
    i++;
  }
  return (1);
}

void goldbach(int n)
{
  int a = 3;
  while (2 * a <= n)
  {
    if (is_prime(a) && is_prime(n - a))
    {
      cout << n << " = " << a << " + " << n - a << "\n";
      return;
    }
    a += 2;
  }
  cout << "Goldbach's conjecture is wrong.\n";
}

int main()
{
  int a;
  vector<int> p;

  while (1)
  {
    cin >> a;
    if (a == 0)
      break;
    p.push_back(a);
  }
  for(int i = 0; i < p.size(); i++)
  {
    goldbach(p[i]);
  }
}
