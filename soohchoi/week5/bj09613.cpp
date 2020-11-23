#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find_gcd(int a, int b)
{
  int n;

  if (a < b)
  {
    n = a;
    a = b;
    b = n;
  }
  while ((n = a % b) != 0)
  {
    a = b;
    b = n;
  }
  return (b);
}

void solution(vector <int> v)
{
  long long sum = 0;
  int i;
  
  for (i = 0; i < v.size();i++)
  {
    for (int j = i + 1; j < v.size(); j++)
    {
      sum += find_gcd(v[i], v[j]);
    }
  }
  cout << sum << "\n";
}


int main() {
  int a;
  int t, n;
  vector <int> v;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while (t > 0)
  {
    cin >> n;
    v.clear();
    while (n > 0)
    {
      cin >> a;
      v.push_back(a);
      n--;
    }
    solution(v);
    t--;
  }
  return 0;
}
