#include <iostream>

using namespace std;
 
int main(void)
{
    int a, b, c;
 
   cin >> a;
   if (cin.fail() == true)
       return (0);
   for(int i = 0; i < a; i++)
   {
       cin >> b >> c;
       cout << "Case #" << i + 1 << ": " << b + c << endl;
   }
}
