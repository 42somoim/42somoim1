#include <cstdio>

using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }
int main() {

    int N, i, j, ans = 0;

    scanf("%d", &N);

    int arr[N];
    int dp[N];

    for (i = 0; i < N; i++) scanf("%d", &arr[i]);
    
    for (i = 0; i < N; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if ( arr[i] < arr[j] && dp[i] < dp[j] + 1 ) dp[i] = dp[j] + 1;
        }
    }

    for (i = 0; i < N; i++) ans = get_max(ans, dp[i]);
    
    printf("%d\n", ans);

    return 0;
}
