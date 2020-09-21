#include <iostream>
#include <vector>

using namespace std;

int solveDp()
{
    int count, num, sum = 0;
    int dp[100001][2] = { 0 };

    cin >> count;
    for (int i = 0; i < count * 2; i++)
    {
        cin >> num;
        if (i < count)
            dp[i][0] = num;
        else
            dp[i - count][1] = num;
    }
    for (int i = 1; i < count; i++)
    {
        if (i == 1)
        {
            dp[1][0] += dp[0][1];
            dp[1][1] += dp[0][0];
        }
        for (int j = 0; j < 2; j++)
        {
            if (i > 1)
            {
                if (j == 0)
                    dp[i][0] += max(dp[i - 1][1], dp[i - 2][1]);
                else if (j == 1)
                    dp[i][1] += max(dp[i - 1][0], dp[i - 2][0]);
            }
        }
    }
    return (max(dp[count - 1][0], dp[count - 1][1]));
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int count;

    cin >> count;
    for (int i = 0; i < count; i++)
        cout << solveDp() << "\n";
}