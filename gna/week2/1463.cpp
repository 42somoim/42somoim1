#include <iostream>
#include <algorithm>
using namespace std; 
#define N_MAX (int)1E6+1
#define INF 987654321
int main() {
    int N; cin >> N;
    int dp[N_MAX];
    for (int n_idx = N; n_idx >= 0; n_idx--) dp[n_idx] = INF;
    dp[N] = 0;
    for (int n_idx = N; n_idx > 0; n_idx--) {
        if (n_idx % 3 == 0)
            dp[n_idx / 3] = min({ dp[n_idx / 3], dp[n_idx] + 1 });
        if (n_idx % 2 == 0)
            dp[n_idx / 2] = min({ dp[n_idx / 2], dp[n_idx] + 1 }); 
 
        dp[n_idx-1] = min({ dp[n_idx-1], dp[n_idx] + 1 });
    }
    cout << dp[1];
    return 0;
}
