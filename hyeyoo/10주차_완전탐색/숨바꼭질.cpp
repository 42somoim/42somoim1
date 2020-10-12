#include <iostream>
#include <queue>

using namespace std;

int ans = -1;

int search(int N, int K)
{
	queue<int> positionq;
	queue<int> timeq;
	bool visited[100000 + 1];
	fill_n(visited, 100000 + 1, false);

	positionq.push(N);
	timeq.push(0);

	while (!positionq.empty()) {
		int u = positionq.front(); positionq.pop();
		int time = timeq.front(); timeq.pop();

		if (u == K)
			return time;
		if (u - 1 >= 0 && !visited[u - 1]) {
			positionq.push(u - 1);
			timeq.push(time + 1);
			visited[u - 1] = true;
		}
		if (u + 1 <= 100000 && !visited[u + 1]) {
			positionq.push(u + 1);
			timeq.push(time + 1);
			visited[u + 1] = true;
			
		} if (2 * u <= 100000 && !visited[2 * u]) {
			positionq.push(2 * u);
			timeq.push(time + 1);
			visited[2 * u] = true;
		}
	}
	return -1;
}

int		main(void)
{
	int N, K;
	cin >> N >> K;

	cout << search(N, K) << endl;

	return 0;
}
