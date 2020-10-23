#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int flag = 0;
  string str;
  int count= 0;
  int ret = 0;
  int temp = 0;

  cin >> str;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '(')
    {
      count++;
      flag = 1;
    }
    else if (str[i] == ')')
    {
      count--;
      if (flag == 1)
      {
        ret = ret + count + temp;
        temp = 0;
      }
      else
        temp++;
      flag = 0;
    }
  }
  ret += temp;
  cout << ret << "\n";
  return 0;
}
