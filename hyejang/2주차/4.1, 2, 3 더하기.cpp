#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int count, num, tmp = 0;
    int dp[11];

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> num;
        for (int j = 3; j < num; j++)
        {
            tmp = dp[j - 1] + dp[j - 2] + dp[j - 3];
            dp[j] = tmp;
        }
        cout << dp[num - 1] << "\n";
    }
}