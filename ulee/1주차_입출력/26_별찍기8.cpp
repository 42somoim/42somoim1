#include <iostream>

using namespace std;
int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << '*';
        for (int k = n - i - 1; k > 0; k--)
            cout << ' ';
        for (int l = n - i - 1; l > 0; l--)
            cout << ' ';
        for (int j = 0; j <= i; j++)
            cout << '*';
        cout << '\n';
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
            cout << '*';
        for (int k = n - i - 1; k > 0; k--)
            cout << ' ';
        for (int l = n - i - 1; l > 0; l--)
            cout << ' ';
        for (int j = 0; j <= i; j++)
            cout << '*';
        cout << '\n';
    }
}
