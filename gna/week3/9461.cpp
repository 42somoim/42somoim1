#include <cstdio>
using namespace std;

int main () {

    int i, T, t, ans = 0;
    long long dp[101] = {0, };
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    scanf("%d", &T);

    for (i = 4; i < 101; i++) dp[i] = dp[i-3] + dp[i-2];

    for (i = 0; i < T; i++) {
        scanf("%d", &t);
        printf("%lld\n", dp[t]);
    }

    printf("\n");
    return 0;
}
