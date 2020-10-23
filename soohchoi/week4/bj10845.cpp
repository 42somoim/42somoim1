#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, num;
  string str;
  vector <int> v;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> str;
    if (str == "push")
    {
      cin >> num;
      v.push_back(num);
    }
    else if(str == "pop")
    {
      if (v.empty())
        cout << "-1" << "\n";
      else
      {
        cout << v.front() << "\n";
        v.erase(v.begin());
      }
    }
    else if (str == "size")
    {
      cout << v.size() << "\n";
    }
    else if (str == "empty")
    {
      cout << (int)v.empty() << "\n";
    }
    else if (str == "front")
    {
      if (v.empty())
        cout << "-1" << "\n";
      else
      {
        cout << v.front() << "\n";
      }
    }
    else if (str == "back")
    {
      if (v.empty())
        cout << "-1" << "\n";
      else
      {
        cout << v.back() << "\n";
      }
    }
    else
      return 0;
  }
  return 0;
}
