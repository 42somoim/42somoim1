#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
 
#define MAX_SIZE 1001
 
using namespace std;
 
void bfs(int start);
 
vector<int> connected[MAX_SIZE];
bool visited[MAX_SIZE];

void bfs(int start) {
    queue<int> q;
 
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
 
        int csize = connected[current].size();
        for (int i = 0; i < csize; i++) {
            int next = connected[current][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
	{
        int u, v;
        scanf("%d %d", &u, &v);
        connected[u].push_back(v);
        connected[v].push_back(u);
    }
 
    int cnt = 0;
    for (int i = 1; i <= n; i++)
	{
        if (!visited[i]) {
            cnt++;
            bfs(i);
        }
    }
    printf("%d\n", cnt);
    return 0;
}