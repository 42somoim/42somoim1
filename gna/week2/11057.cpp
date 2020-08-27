#include <cstdio>

using namespace std;

int main() {
    int DP[1001][10] = {};
    int ans, N;
    ans = 0;

    scanf("%d", &N);

    for (int i = 0; i < 10; i++) {
        DP[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                DP[i][j] = (DP[i][j] + DP[i-1][k]) % 10007;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        ans = (ans + DP[N][i]) % 10007;
    }

    printf("%d\n", ans);

    return 0;
}
