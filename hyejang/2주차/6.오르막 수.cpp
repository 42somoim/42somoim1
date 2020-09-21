#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, sum = 0;
    int dp[1001][10] = { 0 };

    cin >> num;
    for (int i = 0; i <= 9; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= num; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k < 10 - j; k++)
                dp[i][j] += dp[i - 1][k + j] % 10007;
    for (int i = 0; i <= 9; i++)
        sum = (sum + dp[num][i]) % 10007;
    cout << sum << "\n";
}