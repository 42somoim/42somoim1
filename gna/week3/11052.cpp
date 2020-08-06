#include <cstdio>
#include <algorithm>
using namespace std;

int n, d[1001], p[1001];

void solve() {
    d[0] = 0, d[1] = p[1];
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            d[i] = max(d[i], d[i-j]+p[j]);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &p[i]);
    solve();
    printf("%d\n", d[n]);
    return 0;
}

