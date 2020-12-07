#include <iostream>

using namespace std;
int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int k = n - i - 1; k > 0; k--)
            cout << ' ';
        for (int j = 0; j <= i + i; j++)
            cout << '*';
        cout << '\n';
    }
}
