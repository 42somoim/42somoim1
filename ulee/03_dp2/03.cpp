#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int N, max_length;
    int dp[1001];
    int r_dp[1001];
    int value[1001];

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> value[i];
        dp[i] = 1;
        r_dp[i] = 1;
    }
    
    max_length = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (value[i] > value[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    for (int i = N; i >= 1; i--)
    {
        for (int j = N; j >= i; j--)
        {
            if (value[i] > value[j] && r_dp[j] + 1 > r_dp[i])
                r_dp[i] = r_dp[j] + 1;
        }
    }
    for (int i = 1; i <= N; i++)
        max_length = max(max_length, dp[i] + r_dp[i] - 1);

    cout << max_length << endl;
}