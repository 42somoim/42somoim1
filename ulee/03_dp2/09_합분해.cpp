#include <iostream>

using namespace std;
int main()
{
    int num, count;
    long long dp[201][201] = {0};

    cin >> num >> count;

    for (int i = 0; i <= num; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= count; i++)
    {
        for (int j = 0; j <= num; j++)
        {
            for (int k = 0; k <= j; k++)
                dp[i][j] +=  dp[i - 1][k];
            dp[i][j] %= 1000000000;
        }
    }

    cout << dp[count][num] << endl;
    return (0);
}