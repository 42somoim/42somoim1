#include <iostream>
#include <algorithm>

using namespace std;

int max_tripple(int one, int two, int three)
{
    int top;

    top = one > two ? one : two;
    top = top > three ? top : three;

    return (top);
}

int main()
{
    int N, max_sum;
    int dp[301], value[301];

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> value[i];

    dp[0] = 0;
    dp[1] = value[1];
    dp[2] = dp[1] + value[2];
    for (int i = 3; i <= N; i++)
    {
        if (i == N)
            dp[i] = max(dp[i - 2] + value[i],  dp[i - 3] + value[i - 1] + value[i]);
        else
            dp[i] = max_tripple(dp[i - 1],  dp[i - 2] + value[i],  dp[i - 3] + value[i - 1] + value[i]);
    }

    cout << dp[N] << endl;
}