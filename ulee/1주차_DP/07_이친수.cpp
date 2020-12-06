#include <iostream>

using namespace std;
int main()
{
    long long dp[91][2] = {0};
    long long result;
    int  n;

    result = 0;
    cin >> n;
    
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];

    }
    result = result + dp[n][0] + dp[n][1];
    cout << result;
}