#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a, b, c, d;
    string s1, s2;

    cin >> a >> b >> c >> d;
    s1 = a + b;
    s2 = c + d;

    cout << stoll(s1) + stoll(s2);
}