#include <iostream>

using namespace std;
int main()
{
    int n;
    int sum;
    string str;

    sum = 0;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++)
        sum += str[i] - '0';
    cout << sum;
    return (0);
}
