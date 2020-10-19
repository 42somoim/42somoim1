#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
using namespace std;

void analysis(string str)
{
  int small = 0, big = 0;
  int num = 0, space = 0;

  for (int i = 0; i < str.size() ; i++)
  {
    if (isupper(str[i]))
      big++;
    else if (islower(str[i]))
      small++;
    else if (isdigit(str[i]))
      num++;
    else if (isspace(str[i]))
      space++;
  }
  cout << small << " " << big << " " << num << " " << space << "\n";

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, num;
  string str;
  vector <string> v;

  while(getline(cin, str))
  {
    v.push_back(str);
  }
  for (int i = 0; i < v.size(); i++)
  {
    str = v[i];
    analysis(str);
  }
  return 0;
}
