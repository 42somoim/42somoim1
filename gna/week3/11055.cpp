#include <cstdio>
using namespace std;

int get_max (int a, int b) { return a > b ? a : b; }

int main() {

    int N, i, j, ans;

    scanf("%d", &N);

    int arr[N];
    int dp1[N];
    int dp2[N];
    
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        dp2[i] = arr[i];
    }
    
    ans = dp2[0];

    for (i = 0; i < N; i++) {
        dp1[i] = 1;
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp1[j]+1 > dp1[i]) {
                dp1[i] = dp1[j] + 1;
                dp2[i] = get_max(dp2[i], dp2[j] + arr[i]);
            }
            ans = get_max(ans, dp2[i]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
