#include <iostream>

using namespace std;
 
int main(void)
{
    int a;
    char b[4];
 
   cin >> a;
   if (cin.fail() == true)
       return (0);
   for(int i = 0; i < a; i++)
   {
       cin >> b;
       if (b[1] == ',')
       cout << b[0] + b[2] - 96 << endl;
   }
}
