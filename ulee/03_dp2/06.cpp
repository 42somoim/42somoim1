#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    int N, max_sum;
    vector<int> dp(100001, 0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[N] << endl;
}