#include <iostream>
#include <string>
 
using namespace std;
 
string N;
int dp[5001];
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    cin >> N;
    if (N[0] == '0') 
    {
        cout << 0;
        return 0;
    }
 
    dp[0] = dp[1] = 1;
    
    for (int i = 2; i <= N.size(); i++)
    {
        char a = N[i - 1], b = N[i - 2];
        if (a == '0' && b =='0')
 	{
            cout << 0;
            return 0;
        }
        if (a != '0') dp[i] += dp[i - 1];
	if (b != '0')
	{
            int num = (b - '0')*10 + (a - '0');
            if (num <= 26) dp[i] += dp[i-2];
        }
        dp[i] %= 1000000;
    }
 
    cout << dp[N.size()];
    return 0;
}
