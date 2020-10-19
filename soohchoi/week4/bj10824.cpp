#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string A, B, C, D;

  cin >> A >> B >> C >> D;
  A += B;
  C += D;
  cout << stoll(A.c_str())+ stoll(C.c_str()) << "\n";
  return 0;
}
