#include <iostream>
using namespace std;

int main() {
  int a, b, lcm;
  int n;

  cin >> a >> b;

  lcm = a * b;
  if (a < b)
  {
    int temp = a;
    a = b;
    b = temp;
  }
  while ((n = a % b) != 0)
  {
    a = b;
    b = n;
  }
  cout << b << " " << lcm / b << "\n";
}
