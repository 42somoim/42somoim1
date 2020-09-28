#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, count = 0;
    int dp[301] = { 0 };
    int arr[301] = { 0 };

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = max(arr[0] + arr[1], arr[1]);
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    for (int i = 3; i < num; i++)
    {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }
    //10 30 50 10

    cout << dp[num - 1] << "\n";
}