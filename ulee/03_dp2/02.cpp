#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int N, max_length;
    int dp[1001];
    int value[1001];

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> value[i];
        dp[i] = 1;
    }
    
    max_length = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (value[i] < value[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    for (int i = 1; i <= N; i++)
        max_length = max(max_length, dp[i]);

    cout << max_length << endl;
}