#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num[5001] = { 0 };
    int dp[5001] = { 0 };
    string code;

    cin >> code;
    for (int i = 1; i < code.length() + 1; i++)
    {
        num[i] = code[i - 1] - 48;
    }
    if (code[0] == '0')
    {
        cout << "0\n";
    }
    else
    {
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= code.length(); i++)
        {
            if (num[i] > 0 && num[i] < 10)
            {
                dp[i] = dp[i - 1] % 1000000;
            }
            if (num[i - 1] * 10 + num[i] > 9 && num[i - 1] * 10 + num[i] < 27 && num[i - 1] != 0)
            {
                dp[i] = (dp[i-2] + dp[i]) % 1000000;
            }
        }
        cout << dp[code.length()] << "\n";
    }

}
//121

//1 2 1
//12 1
//1 21


//1212

//1 2 1 2
//12 1 2
//12 12
//1 2 12
//1 21 1



//1231

//1 2 3 1
//12 3 1
//12 31x
//1 2 31x
//1 23 1