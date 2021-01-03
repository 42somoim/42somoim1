#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;

    getline(cin, s);
    for (int i = 0; s[i]; ++i)
    {
        if (('a' <= s[i] && s[i] <= 'm') || ('A' <= s[i] && s[i] <= 'M'))
            s[i] += 13;
        else if (('n' <= s[i] && s[i] <= 'z') || ('N' <= s[i] && s[i] <= 'Z'))
            s[i] -= 13;
        cout << s[i];
    }

}