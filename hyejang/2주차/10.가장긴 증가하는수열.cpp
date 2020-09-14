#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num, count = 0, tmp;
    int dp[1001] = { 0 };
    int arr[1001] = { 0 };

    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    for (int i = 0; i < num; i++)
    {
        tmp = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                tmp = max(tmp, dp[j]);
        }
        dp[i] = tmp + 1;
        count = max(count, dp[i]);
    }
    cout << count << "\n";
}



