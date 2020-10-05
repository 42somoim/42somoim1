#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    int dp[31] = { 0 };

    cin >> num;
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 4; i <= num; i+=2)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[i - j] * 2;
        }
    }

    cout << dp[num] << "\n";
}