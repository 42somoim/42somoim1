#include <iostream>

using namespace std;
int main()
{
    int n, element;
    int max, min;

    cin >> n;
    max = -1000000;
    min = 1000000;
    for (int i = 0; i < n;  i++)
    {
        cin >> element;
        if (element > max)
            max = element;
        if (element < min)
            min = element;
    }
    cout << min << " " << max;
}
