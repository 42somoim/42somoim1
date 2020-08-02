#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
#define NMAX 100000 + 1
#define IS_USED 2
#define ROW 2 
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        int stickers[ROW][NMAX] = { 0 };
        int dp[ROW][NMAX][IS_USED] = { 0 };
        
        // 입력받기 
        for (int col = 1; col <= n; col++)    scanf("%d", &stickers[0][col]);
        for (int col = 1; col <= n; col++)    scanf("%d", &stickers[1][col]);
        
        // dp를 갱신합니다.
        int answer = 0; 
        for (int col = 1; col <= n; col++) {
            // 이번 col 에 있는 스티커를 안 떼면, 이전 단계에서 위/아래의 최대값 중 하나를 취함
            dp[0][col][0] = max({ dp[0][col - 1][0], dp[0][col - 1][1],
                                    dp[1][col - 1][0], dp[1][col - 1][1] });
            dp[1][col][0] = max({ dp[0][col - 1][0], dp[0][col - 1][1],
                                    dp[1][col - 1][0], dp[1][col - 1][1] });
            // 이번 col 에 있는 스티커를 떼면, 이전 단계에서 같은 col 을 뗐을 경우는 무시
            dp[0][col][1] = max({ dp[0][col - 1][0], dp[1][col - 1][0],
                                    dp[1][col - 1][1]}) + stickers[1][col];
            dp[1][col][1] = max({ dp[0][col - 1][0], dp[0][col - 1][1], 
                                    dp[1][col - 1][0] }) + stickers[0][col];
            
            answer = max({ dp[0][col][0], dp[0][col][1], dp[1][col][0], dp[1][col][1] });
        }
        printf("%d\n", answer);
    }
    return 0;
}
