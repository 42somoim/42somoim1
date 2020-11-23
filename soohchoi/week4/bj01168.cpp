#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector <int> arr(n);
  for (int i = 0; i < n; i++)
  {
    arr[i] = i + 1;
  }
  int index = 0;
  vector <int> answer;
  while (!arr.empty())
  {
    index = (index + m - 1) % arr.size();
    answer.push_back(arr[index]);
    arr.erase(arr.begin()+index);
  }
  cout << "<";
  for (int i = 0; i < n; i++)
  {
    cout << answer[i];
    if (i < n - 1)
      cout <<", ";
  }
  cout << ">\n";
  return 0;
}
