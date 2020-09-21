#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long dp[92] = { 0 };
    int num;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    cin >> num;
    for (int i = 3; i <= num; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    cout << dp[num] << "\n";
}
