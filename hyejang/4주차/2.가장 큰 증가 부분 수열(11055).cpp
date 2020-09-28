#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, count = 0, tmp = 0;
    int dp[1001] = { 0 };
    int arr[1001] = { 0 };

    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] =  max(dp[i], dp[j] + arr[i]);
            }
        }
        count = max(dp[i], count);
    }
    cout << count << "\n";
}
