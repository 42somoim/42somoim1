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
        for (int j = 0; j < count; j++)
        {
            if (count - i > j + 1)
                cout << " ";
            else
                cout << "*";
        }
        cout << "\n";
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (j <= i)
                cout << " ";
            else
                cout << "*";
        }
        cout << "\n";
    }
}
