#include <iostream>

using namespace std;
int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i - 1; j++)
            cout << ' ';
        for (int k = n - i; k >= 0; k--)
            cout << '*';
        cout << '\n';
    }
}
