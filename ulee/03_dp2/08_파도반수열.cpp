#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int N,T;
    vector<long long> dp(101, 0);
    
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    for (int i = 1; i <= N; i++)
    {
        cin >> T;
        for (int i = 7; i <= T; i++)
            dp[i] = dp[i - 1] + dp[i - 5];
        cout << dp[T] << endl;
    }

}