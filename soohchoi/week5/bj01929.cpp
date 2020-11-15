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
  int a, b;
  vector<int> p;

  cin >> a >> b;
  for (int i = a; i <= b; i++)
  {
    if(is_prime(i))
      cout << i << "\n";
  }
}
