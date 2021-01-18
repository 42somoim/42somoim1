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

vector<vector<pair<long long, long long> > > graph;
long long N, M;

void dfs(long long v, long long dep) {
  depth[v] = dep;
  visited[v] = true;

  for (pair<long long, long long> next : graph[v]) {
    if (!visited[next.second]) {
      parent[next.second][0] = v;
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

long long   kth_vertex(long long u, long long v, long long kth) {
  long long sum = 0;
  long long i;
  long long common = lca(u, v);
  long long x = u;
  long long y = v;

  kth--;
  /* u->common로 이동, 얼마나? min(kth, depth[common] - depth[u])만큼 */
  i = 0;
  for (long long k = MAX_K; k >= 0; k--) {
    long long next = parent[x][k];
    if (next != 0 && sum + (1 << k) <= min(kth, depth[u] - depth[common])) {
      sum += (1 << k);
      x = next;
    }
  }

  if (sum == kth)
    return x;

  /* v->common로 이동, 얼마나? lca에서 v까지의 depth차에서 남은 depth를 뺀만큼 */
  long long sum2 = 0;
  for (long long k = MAX_K; k >= 0; k--) {
    long long prev = parent[y][k];
    if (prev != 0 && sum2 + (1 << k) <= (depth[v] - depth[common]) - (kth - sum)) {
      sum2 += (1 << k);
      y = prev;
    }
  }
  return y;
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
    long long cmd, u, v, k;
    cin >> cmd >> u >> v;
    if (cmd == 1) {
      cout << (dist[u] + dist[v] - 2 * dist[lca(u, v)]) << "\n";
    } else if (cmd == 2) {
      cin >> k;
      cout << kth_vertex(u, v, k) << "\n";
    }
  }
  return 0;
}
