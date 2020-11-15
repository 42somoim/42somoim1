#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void solution(string n)
{
  int i = n.length() - 1;
  int count = 0;
  int temp = 0;
  vector <int> ret;

  while (i >= 0)
  {
    if (count < 3)
    {
      temp += (n[i] - '0') * pow(2, count);
      count++;
    }
    else if (count == 3)
    {
      count = 0;
      ret.push_back(temp);
      temp = 0;
      i++;
    }
    i--;
  }
  ret.push_back(temp);
  for (i = ret.size() - 1; i >= 0; i--)
  {
    cout << ret[i]; 
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string n;

  cin >> n;
  solution(n);
  return 0;
}
