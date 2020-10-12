#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, count = -9999999;
    int dp[100001] = { 0 };
    int arr[100001] = { 0 };

    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= num; i++)
    {
        if (dp[i - 1] + arr[i] > arr[i])
        {
            dp[i] = dp[i - 1] + arr[i];
        }
        else
        {
            dp[i] = arr[i];
        }
        count = max(dp[i], count);
    }
    cout << count << "\n";
}