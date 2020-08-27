#include <iostream>
#include <string>

using namespace std;

 

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        for (int i = 0; i < 100; i++)
        {
                 string s;
                 getline(cin, s);
                 if (s.length() == 0)
                         break;
                 int upper = 0, lower = 0, number = 0, space = 0;
                 for (int j = 0; j < s.length(); j++)
                         if (s[j] >= 'A' && s[j] <= 'Z')
                                 upper++;
                         else if (s[j] >= 'a' && s[j] <= 'z')
                                 lower++;
                         else if (s[j] >= '0' && s[j] <= '9')
                                 number++;
                         else if(s[j] == ' ')
                                 space++;
                 cout << lower << " " << upper << " " << number << " " << space << "\n";
        }
        return 0;
}
