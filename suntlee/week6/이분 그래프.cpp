#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <cstring>
 
#define MAX_SIZE 20000+1
#define RED  1
#define BLUE 2
 
using namespace std;
 
int K, V, E;
vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];
 
void bfs(int start)
{
    queue<int> q;
    int color = RED; // 시작 노드의 default 색상은 RED.
 
    visited[start] = color;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
 
        if (visited[now] == RED) {
            color = BLUE;
        }
        else if (visited[now] == BLUE) {
            color = RED;
        }
 
        int gsize = graph[now].size();
        for (int i = 0; i < gsize; i++) {
            int next = graph[now][i];
            if (!visited[next]) {
                visited[next] = color;
                q.push(next);
            }
        }
    }
}
 
void dfs(int start)
{
    if (!visited[start]) {
        visited[start] = RED;
    }
 
    int gsize = graph[start].size();
    for (int i = 0; i < gsize; i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            if (visited[start] == RED) {
                visited[next] = BLUE;
            }
            else if (visited[start] == BLUE) {
                visited[next] = RED;
            }
            dfs(next);
        }
    }
}
 
bool isBipartiteGraph()
{
    for (int i = 1; i <= V; i++) {
        int gsize = graph[i].size();
        for (int j = 0; j < gsize; j++) {
            int next = graph[i][j];
            if (visited[i] == visited[next]) {
                return 0;
            }
        }
    }
    return 1;
}
 
int main()
{
    scanf("%d", &K);
    while (K--) {
        scanf("%d %d", &V, &E);
        
        for (int i = 0; i < E; i++) {
            int f, s;
            scanf("%d %d", &f, &s);
            graph[f].push_back(s);
            graph[s].push_back(f);
        }
 
        for (int i = 1; i <= V; i++) { 
            if (!visited[i]) {
                bfs(i);
                //dfs(i);
            } 
        }
 
        if (isBipartiteGraph()) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
 
        for (int i = 0; i <= V; i++) {
            graph[i].clear();
        }
        memset(visited, false, sizeof(visited));
    }
    return 0;
}
