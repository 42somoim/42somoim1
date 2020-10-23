#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str, temp;
  vector <string> v;

  cin >> str;
  for (int i = 0 ; i < str.size() ; i++)
  {
    temp = str.substr(i, str.size() - i);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << "\n";
  }
  return 0;
}
