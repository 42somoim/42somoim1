#include <iostream>
#include <string>

using namespace std;
int main()
{
    int arr[5001 = {0}];    // 각 자리의 값
    long long dp[5001] = {0};     // 각 자리의 가짓수
    int len;          
    string str;
    int temp;
    
    // 입력받은 후 길이 len에 담음 
    cin >> str;
    len = str.length();
    
    // 입력된 값이 0일 경우 0출력 후 종료
    if (len == 1 && str[0] == '0')
    {
        cout << 0 << endl;
        exit (0);
    }
    
    // arr배열 세팅.
    for (int i = 1; i <= len; i++)
        arr[i] = str[i - 1] - '0';
    
    // dp배열 세팅
    dp[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        if (1 <= arr[i] && arr[i] <= 9)
        {
            dp[i] = dp[i - 1] + dp[i];
            dp[i] %= 1000000;
        }

        if (i == 1)
            continue;

        temp = arr[i] + arr[i - 1] * 10 ;
        if (10 <= temp && temp <= 26)
        {
            dp[i] = dp[i - 2] + dp[i];
            dp[i] %= 1000000;
        }
    }

    // 출력
    cout << dp[len] << endl;
}