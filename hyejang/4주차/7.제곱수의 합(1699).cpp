#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, count = 0;
    int dp[100001] = { 0 };
    int tmp = 0;

    cin >> num;

    //dp[1] = 1;
    //dp[2] = 2;
    //dp[3] = 3;
    //dp[4] = 1;
    //dp[5] = 2;
    //dp[6] = 3;
    //dp[7] = 4;
    //dp[8] = 2;
    dp[1] = 1;
    for (int i = 1; i <= num + 1; i++)
    {
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (dp[i] > dp[i - j * j] + 1 || dp[i] == 0)
                dp[i] = dp[i - j * j] + 1;
        }
    }

    cout << dp[num] << "\n";
}