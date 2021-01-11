#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int dp[1001] = {0}, arr[10001] = {0};
    int N;
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    dp[0] = 0;
    for (int i = 1; i<= N; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], dp[i - j] + arr[j]);
    }

    cout << dp[N] << endl;