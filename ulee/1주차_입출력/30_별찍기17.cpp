#include <iostream>

using namespace std;
int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = n - i - 1; k > 0; k--)
            cout << ' ';
        cout << "*";
        for (int l = 0; l < i + i - 1; l++)
            cout << ' ';
        if (i == 0)
            cout << "\n";
        else
            cout << "*\n";
    }
    for (int j = 0; j < n + n - 1; j++)
        cout << '*';
}
