#include <iostream>

using namespace std;
int main()
{
    int n;
    int sum;

    cin >> n;
    sum = 0;
    for (int i = 1; i <= n;  i++)
        sum += i;
    cout << sum;
}
