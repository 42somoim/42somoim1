#include<iostream>
#include<cstdio>
using namespace std;
 
int arr[11][11];  //map.
int check[11];  //도시를 방문 했는지 check
int n;          //n.
int m = 987654321;  //순회의 최소 비용
 
void input(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}
 
void dfs(int start, int y, int sum, int cnt){
    //모든 도시를 들렀고(cnt==n) && 다시 스타트 도시로 온 경우(start==y)
    if(cnt == n && start == y){
        if(m > sum) m = sum;
        return;
    }
 
    for(int x=0; x<n; x++){
        if(arr[y][x] == 0) continue;    //연결 되지 않은 경우(자기자신포함)
 
        //방문 하지 않고 y,x가 0보다 큰 경우
        if(!check[y] && arr[y][x] >0) {
            check[y] = true;    //방문 체크
            sum+=arr[y][x];
 
            if(sum <= m){   //sum이 m 보다 작은 경우만 탐색 진행
                //[1,2]이었으면 [2,-]로 보내줌.
                dfs(start, x, sum, cnt+1);
            }
 
            //방문한 기록과 합 초기화
            check[y] = false;
            sum-=arr[y][x];
        }
    }
}
 
void solution(){
    for(int y=0; y<n; y++){
        //각각의 점(도시)에서 시작하는 경우
        dfs(y, y, 0, 0);
    }
}
 
 
void output(){
    printf("%d", m);
}
 
int main(void){
    input();
    solution();
    output();
    return 0;
}
 