#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  int n[26] = {};

  cin >> a;
  for (int i = 0; a[i] != '\0' ; i++)
  {
    n[(int)a[i] - 97]++;
  }
  for (int i = 0; i < 25; i++)
  {
    cout << n[i] << " ";
  }
  cout << n[25] << "\n";
}
