#include<iostream>
 
#define MAX 2001
using namespace std;
 
int N;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
 
        x1 = (x1 + 500) * 2;
        y1 = (y1 + 500) * 2;
        x2 = (x2 + 500) * 2;
        y2 = (y2 + 500) * 2;
 
        for (int i = x1; i <= x2; i++)
        {
            MAP[y1][i] = 1;
            MAP[y2][i] = 1;
        }
        for (int i = y1; i <= y2; i++)
        {
            MAP[i][x1] = 1;
            MAP[i][x2] = 1;
        }
    }
}
 
void DFS(int y, int x)
{
    if (y < 0 || x < 0 || x >= MAX || y >= MAX) return;
    if (MAP[y][x] == 2 || MAP[y][x] == 0) return;
 
    MAP[y][x] = 2;
 
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        DFS(ny, nx);
    }
}
 
void Solution()
{
    int Pu_Cnt;
 
    Pu_Cnt = 0;
 
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (MAP[i][j] == 1)
            {
                DFS(i, j);
                Pu_Cnt++;
            }
        }
    }
 
    if (MAP[1000][1000] == 2) Pu_Cnt--;
    cout << Pu_Cnt << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
 
    return 0;
}
