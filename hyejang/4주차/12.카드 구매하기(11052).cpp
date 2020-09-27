#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int maxCard, cardValue[1001];
    int dp[10001] = { 0 };

    cin >> maxCard;
    for (int i = 1; i <= maxCard; i++)
    {
        cin >> cardValue[i];
    }
    dp[1] = cardValue[1];
    for (int i = 2; i <= maxCard; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], cardValue[j] + dp[i - j]);
        }
    }
    cout << dp[maxCard] << "\n";
}

//2
//1, 5
//dp[2] = cardValue[1] + cardValue[1] vs cardValue[2];

// 3
//1 , 5, 7
//dp[2] = cardValue[1] + cardValue[1] vs cardValue[2];
//dp[3] = max(10 + cardValue[1], cardValue[3] + cardValue[2])

//3
//1, 5, 7
//dp[1] = 1, dp[2] = 10, dp[3] = 15
// ->dp[2] ==> 2 < 10,  dp[3] ==> 7 + 5 < 10 + 5

//4
//1, 5, 7 9
//dp[1] = 1, dp[2] = 10, dp[3] = 8, dp[4] = 20;

//5
//10,9,8,7,6
//dp[1] = 10;, dp[2] = 20