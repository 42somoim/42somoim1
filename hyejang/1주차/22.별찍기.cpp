#include <iostream>

using namespace std;

int		main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int count;

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        for (int j = -1; j < i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}
