#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, count = 0;
    int tmp = 0, tmp1 = 0;
    int dp[1001] = { 0 };
    int backDp[1001] = { 0 };
    int arr[1001] = { 0 };
    int backArr[1001] = { 0 };

    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= num; i++)
    {
        backArr[i] = arr[num - i + 1];
    }

    for (int i = 1; i <= num; i++)
    {
        tmp = 0;
        tmp1 = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                tmp = max(dp[j], tmp);
            }
            dp[i] = tmp + 1;

            if (backArr[i] > backArr[j])
            {
                tmp1 = max(backDp[j], tmp1);
            }
            backDp[i] = tmp1 + 1;
        }
    }
    for (int i = 1; i <= num; i++)
    {
        count = max(dp[i] + backDp[num - i + 1] - 1, count);
    }
    cout << count << "\n";
}