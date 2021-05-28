#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, lcm = 0, gcd;
    int high, low, high_c, low_c;

    cin >> a >> b;
    for (int i = 1; i <= a; ++i)
    {
        if (a % i == 0 && b % i == 0 && i > lcm)
            lcm = i;
    }

    if (a > b)
    {
        high = a; low = b; high_c = a; low_c = b;
    }
    else
    {
        high = b; low = a; high_c = b; low_c = a;
    }
    while (true)
    {
        if (low == high)
        {
            gcd = low;
            break;
        }
        if (low > high) high += high_c;
        else low += low_c;
    }

    cout << lcm << "\n" << gcd;
}
