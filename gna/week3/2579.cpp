#include <cstdio>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main () {

    int n, i;
    int arr[300];
    int dp[300];

    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    dp[0] = arr[0];
    dp[1] = max(arr[0]+arr[1], arr[1]);
    dp[2] = max(arr[0]+arr[2], arr[1]+arr[2]);

    for (i = 3; i < n; i++) dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
    printf("%d\n", dp[n-1]);

    return 0;
}
