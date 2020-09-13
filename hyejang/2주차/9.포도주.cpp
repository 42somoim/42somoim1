#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    int wine[10001] = { 0 };
    int dp[10002] = { 0 };

    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> wine[i];
    dp[1] = wine[0];
    if (num > 1)
        dp[2] = wine[0] + wine[1];
    for (int i = 3; i <= num; i++)
    {
        dp[i] = max(wine[i - 1] + dp[i - 2], dp[i - 1]);
        dp[i] = max(dp[i],wine[i - 1] + wine[i - 2] + dp[i - 3]);
    }
    cout << dp[num] << "\n";
}