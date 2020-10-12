#include <iostream>
 
using namespace std;
 
int n;
int board[2500][2500];
int ans[3];
 
void solve(int x, int y, int size)
{
    int first = board[x][y];
    bool isallsame = true;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (first != board[i][j]) {
                isallsame = false;
                break;
            }
        }
        if (!isallsame)
			break;
    }
    if (isallsame) {
        ans[first + 1]++;
        return;
    }
    int k = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            solve(x + i * k, y + j * k, k);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
			cin >> board[i][j];
        }
    }
    solve(0, 0, n);
    for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';
}

