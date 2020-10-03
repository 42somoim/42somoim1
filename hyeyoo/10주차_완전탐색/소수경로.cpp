#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int		bfs(bool *isPrime, int from, int to) {
	queue<int> q;
	queue<int> timeq;
	bool visited[10000];
	fill_n(visited, 10000, false);
	q.push(from);
	timeq.push(0);
	visited[from] = true;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		int time = timeq.front(); timeq.pop();
		if (u == to)
			return time;
		int now_ten = 10;
		int prev_ten = 1;
		for (int i = 0; i < 4; i++) {
			int num = u - (u % now_ten) + (u % prev_ten);
			for (int digit = 0; digit < 10; digit++) {
				int next = num + prev_ten * digit;
				if (next < 1000)
					continue;
				if (isPrime[next] && !visited[next]) {
					visited[next] = true;
					q.push(next);
					timeq.push(time + 1);
				}
			}
			now_ten *= 10;
			prev_ten *= 10;
		}
	}
	return -1;
}

int		main(void)
{
	int T;
	bool isPrime[10000];
	fill_n(isPrime, 10000, true);

	for (int i = 2; i < 10000; i++) {
		if (!isPrime[i])
			continue;
		for (int j = 2 * i; j < 10000; j += i) {
			isPrime[j] = false;
		}
	}

	cin >> T;
	while (T--) {
		int from, to;
		cin >> from >> to;
		int ans = bfs(isPrime, from, to);
		if (ans < 0) {
			cout << "Impossible" << endl;
		} else {
			cout << ans << endl;
		}
	}

	return 0;
}
