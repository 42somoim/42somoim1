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
       printf("Case #%d: %d + %d = %d\n", i + 1, b, c, b + c);
   }
}
