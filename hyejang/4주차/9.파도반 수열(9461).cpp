#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, count;
    long long dp[101] = { 1, 1, 1, 2, 2 };

    cin >> count;
    for (int j = 0; j < count; j++)
    {
        cin >> num;
        for (int i = 5; i <= num; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 3];
        }
        cout << dp[num - 1] << "\n";
    }

}