#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long  b)
{
    long long  t;

    while (a)
    {
        t = a;
        a = b % a;
        b = t;
    }
    return (b);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b, n;

    cin >> a >> b;
    n = gcd(a, b);
    while (n--) cout << 1;

    cout << "\n";
}
