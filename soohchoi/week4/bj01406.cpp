#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  int M;
  char C, I;
  vector <char> s1;
  vector <char> s2;

  cin >> str >> M;
  for (int i = 0; i < str.size(); i++)
  {
    s1.push_back(str[i]);
  }
  for (int i = 0; i < M; i++)
  {
    cin >> C;
    if (C == 'L')
    {
      if (!(s1.empty()))
      {
        s2.push_back(s1.back());
        s1.pop_back();
      }
    }
    else if (C == 'D')
    {
      if (!(s2.empty()))
      {
        s1.push_back(s2.back());
        s2.pop_back();
      }
    }
    else if (C == 'B')
    {
      if (!(s1.empty()))
      {
        s1.pop_back();
      }
    }
    else if (C == 'P')
    {
      cin >> I;
      s1.push_back(I);
    }
  }
  while (!(s1.empty()))
  {
    s2.push_back(s1.back());
    s1.pop_back();
  }
  while (!(s2.empty()))
  {
    cout << s2.back();
    s2.pop_back();
  }
  return 0;
}
