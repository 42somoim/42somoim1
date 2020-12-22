#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    long long N, max_sum;
    long long dp[100001], value[100001];

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> value[i];

    max_sum = dp[1] = value[1];
    for (int i = 2; i <= N; i++)
    {
        dp[i] = max(value[i], dp[i - 1] + value[i]);
        if (max_sum < dp[i])
            max_sum = dp[i];
    }

    cout << max_sum << endl;
}