#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  string str;
  vector <string> v;
  int count;

  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> str;
    v.push_back(str);
  }
  for (int i = 0; i < T; i++)
  {
    str = v[i];
    count = 0;
    for (int j = 0; j < str.size(); j++)
    {
      if (str[j] == '(')
        count++;
      else if (str[j] == ')')
        count--;
      if (count < 0)
        break;
    }
    if (count == 0)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
  return 0;
}
