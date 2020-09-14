#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstring>
 
#define MAX_SIZE 50
 
using namespace std;
 
int w, h;
int NumberOfLand = 0;
int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
 
// 우,하,좌,상,우상,우하,좌상,좌하
int dw[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dh[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };
 
void bfs(int h, int w) {
    queue< pair<int, int> > q; // 이용할 큐, (h,w)
    q.push(make_pair(h, w));
    
    // 처음 h,w를 방문 했기 때문에
    visited[h][w] = true;
    while (!q.empty()) {
        // 큐의 현재 원소를 꺼내기
        h = q.front().first;
        w = q.front().second;
        q.pop();
 
        // 해당 위치의 주변을 확인
        for (int i = 0; i < 8; i++) {
            int nh = h + dh[i];
            int nw = w + dw[i];
 
            // 지도를 벗어나지 않고,
            if (0 <= nw && 0 <= nh && nw < MAX_SIZE && nh < MAX_SIZE) {
                // 섬이면서 방문하지 않았다면
                if (graph[nh][nw] && !visited[nh][nw]) {
                    visited[nh][nw] = true;
                    q.push(make_pair(nh, nw));
                }
            }
        }
    }
}
 
void dfs(int h, int w) {
    // 처음 h,w를 방문 했기 때문에
    visited[h][w] = true;
 
    // 해당 위치의 주변을 확인
    for (int i = 0; i < 8; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];
 
        // 지도를 벗어나지 않고,
        if (0 <= nw && 0 <= nh && nw < MAX_SIZE && nh < MAX_SIZE) {
            // 섬이면서 방문하지 않았다면
            if (graph[nh][nw] && !visited[nh][nw]) {
                visited[nh][nw] = true;
                dfs(nh, nw);
            }
        }
    }
}
 
int main() {
    while (1) {
        scanf("%d %d", &w, &h);
        /* w=0 이면서 h=0이면 종료 */
        if (!w && !h) break;
 
        /* 그래프 정보 입력 */
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%1d", &graph[i][j]);
            }
        }
 
        /* 그래프를 BFS 또는 DFS를 통해 탐색 */
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                // 땅이 존재하고(1), 방문하지 않았을 때(0)
                if (graph[i][j] && !visited[i][j]) {
                    NumberOfLand++;
                    bfs(i,j);
                    //dfs(i, j);
                }
            }
        }
 
        /* 섬의 개수를 출력 */
        printf("%d\n", NumberOfLand);
 
        /* 그래프 및 방문기록, 섬의 개수 초기화 */
        memset(graph, false, sizeof(graph));
        memset(visited, false, sizeof(visited));
        NumberOfLand = 0;
    }
    return 0;
}
