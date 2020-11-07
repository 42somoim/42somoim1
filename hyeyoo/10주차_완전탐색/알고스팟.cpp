#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int INF = 2100000000;
vector<pair<int, int> > adj[10000];
int n, m;
char map[100][100];

vector<int> dijkstra(int src) {
    vector<int> dist(n * m, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        /* 큐에 넣은 시점보다 더 짧은 거리가 갱신된 경우 */
        if (dist[here] < cost) continue;
        /* 인접 정점 확인 */
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(nextDist, there));
            }
        }
    }
    return dist;
}

int     main(void) {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    /* make graph */
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                    adj[y * m + x].push_back(make_pair(ny * m + nx, map[ny][nx] - '0'));
                }
            }
        }
    }

    vector<int> dist = dijkstra(0);
    int ans = dist[n * m - 1];
    cout << ans << endl;
}
