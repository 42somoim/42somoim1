#include<iostream>
#include<queue>
using namespace std;
#define MAX_VALUE 100001 //인덱스 100000까지 :: +1까지 넣음
bool visit[MAX_VALUE];
int N, M;        //N    수빈이위치, M 동생위치
 
int bfs(int n, int m) {
    int time = 0;        //몇초만에 찾았는지 ?
    queue<int> q;
    q.push(n);
 
    while(1) {
        int size = q.size();
 
        for(int i=0; i<size; i++) {
            n = q.front();
            q.pop();
            if(n == m)
                return time;        
            if(n > 0 && visit[n-1] == 0) {
                q.push(n-1);
                visit[n-1] = 1;
            }
            if(n < 100000 && visit[n+1] == 0) {
                q.push(n+1);
                visit[n+1] = 1;
            }
            if(n*2 <= 100000 && visit[n*2] == 0) {
                q.push(n*2);    
                visit[n*2] = 1;
            }
        }
        time++;
    }
}
 
int main()
{
    cin >> N >> M;
    cout << bfs(N, M);
    return 0;
}
