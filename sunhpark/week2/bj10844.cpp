#include <iostream>
#define mod 1000000000
using namespace std;

int        dp[101][10];

void    initDp()
{
    for (int i = 1; i <= 9; ++i)
    {
        dp[1][i] = 1;
    }
}

long long int    findDp(int    n)
{
    long    long    int        sum = 0;

    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        }
    }

    for (int i = 0; i <= 9; ++i)
    {
        sum += dp[n][i];
    }

    return (sum);
}

int        main(void)
{
    int        n;
    
    initDp();
    cin >> n;

    cout << findDp(n) % mod << endl;

    return (0);
}
