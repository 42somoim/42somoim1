#include <iostream>

using namespace std;

int		main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int min = 0, max = 0, num, count;

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> num;
        if (num > max || max == 0)
            max = num;
        if (num < min || min == 0)
            min = num;
    }
    cout << min << " " << max << "\n";
}
