#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, a, b, t;
    int a_c, b_c;

    cin >> N;

    while (N--)
    {
        cin >> a >> b;
        a_c = a;
        b_c = b;
        while (a)
        {
            t = a;
            a = b % a;
            b = t;
        }
        cout << a_c * b_c / b << "\n";
    }
    return (0);
}
