#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int N, max_sum;
    int dp[1001], value[1001];

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> value[i];
        dp[i] = value[i];
    }

    max_sum = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (value[i] > value[j] && dp[i] < dp[j] + value[i])
                dp[i] = dp[j] + value[i];
            max_sum = max(max_sum, dp[i]);
        }
    }

    cout << max_sum << endl;
}