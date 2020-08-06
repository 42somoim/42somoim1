#include <iostream>
#include <cmath>
 
using namespace std;
 
int dp[100001] = { 0 };
 
int main()
{
    int N;
    int cnt = 0;
    cin >> N;
 
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
 
    for (int i = 4;i <= N;i++) {
        int minvalue = 10000000;
        int j = sqrt(i);
        if (j*j == i) {
            dp[i] = 1;
        }
        else {
            for (int k = 2;k <= j;k++) {
                if ((dp[i - (k*k)] + 1) < minvalue) {
                    minvalue = dp[i - (k*k)] + 1;
                }
            }
            dp[i] = minvalue;
        }
    }
 
    cout << dp[N];
}
