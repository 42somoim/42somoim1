#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main()
{

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    bool traverse;
    int m, n, i, j, k, seg = 0, cnt = 0, ans = 0;
    queue<pair<int, int> > q;

    scanf("%d %d", &m, &n);

    int arr[n+1][m+1];
    bool v[n+1][m+1];
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            v[i][j] = false;
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1) {
                q.push(make_pair(i, j));
                seg++;
            }
        }
    }

    while(!q.empty()) {
        cnt = 0;
        traverse = false;
        for (i = 0; i < seg; i++) {

            pair<int, int> newc = q.front();
            q.pop();

            v[newc.first][newc.second] = true;

            for (k = 0; k < 4; k++) {
                int newy = newc.first + dy[k];
                int newx = newc.second + dx[k];

                if (newx > 0 && newx <= m && newy > 0 && newy <= n && !v[newy][newx] && arr[newy][newx] == 0) {
                    traverse = true;
                    arr[newy][newx] = 1;
                    q.push(make_pair(newy, newx));
                    cnt++;
                }
            }
        }
        seg = cnt;
        if (traverse) ans++;
    }

    bool check = true;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (!v[i][j] && arr[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}