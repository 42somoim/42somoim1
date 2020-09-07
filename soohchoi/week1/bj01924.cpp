#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int x, y, i;
  int sum = 0;
  string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};  
  cin >> x >> y;
  sum += y;
  for (i = 1;i < x; i++)
  {
    if (i == 4 || i == 6 || i == 9 || i == 11)
      sum += 30;
    else if (i == 2)
      sum += 28;
    else
      sum += 31;
  }
  cout << day[sum % 7] << "\n";
  return 0;
}
