// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     cin.tie(NULL);
//     ios::sync_with_stdio(false);

//     int num, count;
//     int dp[201][201] = { 0 };

//     cin >> count;  
//     cin >> num;
//     for (int i = 1; i < 200; i++)
//     {
//         dp[i][1] = 1;
//         dp[i][2] = i + 1;
//     }
//     for (int i = 3; i <= num; i++)
//     {
//         for (int j = 3; j <= count; j++)
//         {
//             if (dp[j - 1][j] == 0)
//             {
//                 dp[j][j] = dp[j - 1][j - 1] * 2 + dp[j][j - 1];
//             }
//             if (dp[j + 1][i] == 0)
//             {
//                 dp[j + 1][i] = dp[j][i] + dp[j + 1][i - 1];
//             }
//         }
//     }
//     cout << dp[count][num] % 1000000000 << "\n";
// }
// N값이 K값보다 작으면 오류

#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int count, num;
    cin >> count >> num;
    long dp[201][201] = { 0 };

    for (int n = 0; n <= count; n++)
    {
        dp[1][n] = 1;
    }

    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j <= count; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] += dp[i - 1][k];
            }
            dp[i][j] %= 1000000000;
        }
    }
    cout << dp[num][count] << endl;
}