#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  long long int d[31] = {};
  
  cin >> n;
  
  if(n % 2 == 0)
  {
    d[0] = 1;
    d[2] = 3;
    for(int i = 4; i <= n; i+= 2)
    {
      d[i] = d[i - 2] * 3;
      for(int j = 4; i - j >= 0; j+= 2)
        d[i] += d[i - j] * 2;
    }
  }
  cout << d[n] << "\n";
}
