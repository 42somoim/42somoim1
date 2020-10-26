#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str;

  getline(cin, str);
  for (int i = 0; i < str.size(); i++)
  {
    if (isupper(str[i]))
    {
      cout << (char)((int)(str[i] - 65 + 13) % 26 + 65);
    }
    else if (islower(str[i]))
    {
      cout << (char)((int)(str[i] - 97 + 13) % 26 + 97);
    }
    else
      cout << (char)str[i];
  }
  cout << "\n";
  return 0;
}
