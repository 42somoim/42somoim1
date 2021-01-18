#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const long long MAX_NODE = 100000;
const long long MAX_K = 20;

long long       parent[MAX_NODE + 1][MAX_K + 1];
long long       depth[MAX_NODE + 1];
bool      visited[MAX_NODE + 1];
long long       dist[MAX_NODE + 1];
long long       longest[MAX_NODE + 1][MAX_K + 1];
long long       shortest[MAX_NODE + 1][MAX_K + 1];

vector<vector<pair<long long, long long> > > graph;
long long N, M;

void dfs(long long v, long long dep) {
  depth[v] = dep;
  visited[v] = true;

  for (pair<long long, long long> next : graph[v]) {
    if (!visited[next.second]) {
      parent[next.second][0] = v;
      longest[next.second][0] = next.first;
      shortest[next.second][0] = next.first;
      dist[next.second] = dist[v] + next.first;
      dfs(next.second, dep + 1);
    }
  }
}

void kth_parent() {
  for (long long k = 1; k <= MAX_K; k++) {
    for (long long i = 1; i <= N; i++) {
      long long mid = parent[i][k - 1];
      parent[i][k] = parent[mid][k - 1];
      longest[i][k] = max(longest[i][k - 1], longest[mid][k - 1]);
      shortest[i][k] = min(shortest[i][k - 1], shortest[mid][k - 1]);
    }
  }
}

long long   lca(long long x, long long y) {
  if (depth[x] > depth[y])
    swap(x, y);

  for (long long k = MAX_K; k >= 0; k--) {
    if (depth[y] - depth[x] >= (1 << k)) {
      y = parent[y][k];
    }
  }

  if (x == y)
    return x;

  long long lca = 0;
  for (long long k = MAX_K; k >= 0; k--) {
    if (parent[x][k] != parent[y][k]) {
      x = parent[x][k];
      y = parent[y][k];
    } else {
      lca = parent[x][k];
    }
  }
  return lca;
}

const int INF = 1000000;

void      solve(long long d, long long e) {
  long long shortest_dist = INF;
  long long longest_dist = 0;
  long long common = lca(d, e);

  /* d->common */
  for (int k = MAX_K; k >= 0; k--) {
    if (depth[d] - depth[common] >= (1 << k)) {
      shortest_dist = min(shortest_dist, shortest[d][k]);
      longest_dist = max(longest_dist, longest[d][k]);
      d = parent[d][k];
    }
  }

  /* e->common */
  for (int k = MAX_K; k >= 0; k--) {
    if (depth[e] - depth[common] >= (1 << k)) {
      shortest_dist = min(shortest_dist, shortest[e][k]);
      longest_dist = max(longest_dist, longest[e][k]);
      e = parent[e][k];
    }
  }

  cout << shortest_dist << " " << longest_dist << "\n";
}

int   main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N;
  graph.resize(N + 1);
  for (long long i = 0; i < N - 1; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(w, v));
    graph[v].push_back(make_pair(w, u));
  }

  dfs(1, 0);
  kth_parent();

  cin >> M; 
  for (long long i = 0; i < M; i++) {
    long long d, e;
    cin >> d >> e;
    solve(d, e);
  }
  return 0;
}
