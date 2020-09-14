#include <iostream>
#include <queue>

using namespace std;
 
int N;
int map[100][100]={0};
int visited[100][100]={0};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
 
struct str
{
    int y,x,cnt;
    str(int y,int x,int cnt):y(y),x(x),cnt(cnt){};
};
queue<str> q;

void dfs(int y,int x,int cnt)
{
 
    for(int i = 0; i < 4; i++)
	{
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        
        if(map[ny][nx] == 0 || visited[ny][nx])
            continue;
        
        visited[ny][nx] = 1;
        q.push(str(ny,nx,cnt));
        
        dfs(ny,nx,cnt);
    }
}
 
int main()
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);
    
    int cnt = 0;
    for(int i = 0; i < N; i++)
	{
        for(int j = 0;j < N; j++)
		{
            if(map[i][j] && !visited[i][j])
			{
                visited[i][j] = 1;
                q.push(str(i,j,++cnt));
                dfs(i,j,cnt);
            }
        }
    }
    
    int ans = 1000;
    int length = 0;
    
    while(!q.empty())
	{
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        
        q.pop();
        queue<str> q2 = q;
        while(!q2.empty())
		{
            int y2 = q2.front().y;
            int x2 = q2.front().x;
            int cnt2 = q2.front().cnt;
            
            q2.pop();
            
            if(cnt2 == cnt)
                continue;
            
            length = abs(y2 - y) + abs(x2 - x) - 1;
            ans = min(ans,length);
        }
    }
    
    cout << ans << '\n';
    return 0;
}