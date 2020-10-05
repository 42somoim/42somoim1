#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int mat[10][10];
bool visited[10];
int N;
int min_cost = INT_MAX;

void travel(int started, int v, int cost) {
	if (started == v && cost != 0) {
		/* 모든 집을 방문해야 함 */
		for (int i = 0; i < N; i++) {
			if (!visited[i])
				return ;
		}
		min_cost = min(min_cost, cost);
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i] && mat[v][i] != 0) {
			visited[i] = true;
			travel(started, i, cost + mat[v][i]);
			visited[i] = false;
		}
	}
}

int		main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int i = 0; i < 10; i++)
			visited[i] = false;
		travel(i, i, 0);
	}
	cout << min_cost << endl;

	return 0;
}
