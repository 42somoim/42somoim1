#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int check[4];

    for (int i = 0; i < 100; i++)
    {
        getline(cin, s);
        if (s.length() == 0)
            break;

        for (int i = 0; s[i]; ++i)
        {   
            if ('a' <= s[i] && s[i] <= 'z') check[0]++;
            else if ('A' <= s[i] && s[i] <= 'Z') check[1]++;
            else if ('0' <= s[i] && s[i] <= '9') check[2]++;
            else if (s[i] == ' ') check[3]++;
        }
            cout << check[0] << " " << check[1] << " " << check[2] << " " << check[3] << "\n"; 
            check[0] = 0; check[1] = 0; check[2] = 0; check[3] = 0;
    }

}