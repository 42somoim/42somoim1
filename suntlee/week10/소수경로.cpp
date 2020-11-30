#include <iostream>
#include <cstring>
#include <queue>
#include <string>

#define max_int 10001
using namespace std;

int n, start_node, end_node;
bool prime[max_int];
int check[max_int];

void eratos() {
    for(int i=2; i*i<max_int; i++){
        for(int j=i*i; j<max_int; j+=i){
            prime[j] = false;
        }
    }
}

int to_int(string num){
    int ret = 0;

    for(int i=0; i<4; i++){
        ret = ret * 10 + (num[i] - '0');
    }

    return ret;
}

// BFS 수행
void bfs(int start){
    queue<int> q;
    q.push(start);
    check[start] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            string node_s = to_string(node);
            for(int j=0; j<10; j++){
                node_s[i] = j + '0';
                int next = to_int(node_s);
                if(next >= 1000 && prime[next] == true && check[next] == -1){
                    check[next] = check[node] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    // 1. 에라토스테네스의 체를 사용해서 9999까지 소수를 모두 표시해 놓는다.
    memset(prime, true, sizeof(prime));
    eratos();

    scanf("%d", &n);

    while(n--){
        // 2. 초기화
        memset(check, -1, sizeof(check));

        scanf("%d %d", &start_node, &end_node);

        bfs(start_node);

        if(check[end_node] != -1){
            printf("%d\n", check[end_node]);
        }
        else{
            printf("Impossible\n");
        }
    }
}