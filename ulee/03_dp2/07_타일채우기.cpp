#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N;
    vector<int> dp(31, 0);
    
    cin >> N;
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    for (int i = 4; i <= N; i += 2)
    {
        dp[i] += dp[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] += dp[j] * 2;
        }
    }

    cout << dp[N] << endl;
}