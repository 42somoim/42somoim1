#include <cmath>
#include <iostream>

using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
  bool check[1000000 + 1];

  int i, j, a, b, n;

  for (i = 1; i <= 1000000; i++) check[i] = true;
  for (i = 2; i <= sqrt(1000000); i++) {
    for (j = i + i; j <= 1000000; j += i) {
      if (check[j] == true) check[j] = false;
    }
  }

  while(1) {
    cin >> n;
    if (n == 0) break;
    i = 3;
    while(1) {
      if (n - i < 0) {
        cout << ("Goldbach's conjecture is wrong.\n");
        break;
      }
      if (check[i] == true && check[n-i] == true) {
        cout << n << " = " << i << " + " <<n - i << '\n';
        break;
      }
      i++;
    }
  }

  return 0;
}