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
        for (int j = 1; j < count - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if ((i + 1 == count) || j == 0 || j >= i * 2)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}
