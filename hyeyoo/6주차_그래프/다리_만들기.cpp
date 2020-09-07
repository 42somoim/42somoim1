/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   다리_만들기.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:57:22 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/03 10:25:44 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int **map;

int		print()
{
	for(int y = 0; y < n; y++) {
		for(int x = 0; x < n; x++) {
			cout << map[y][x] << ' ';
		}
		cout << endl;
	}
	return 0;
}

void	color(int x, int y, int color)
{
	queue<int> qx;
	queue<int> qy;
	bool **visited = new bool*[n];
	for (int y = 0; y < n; y++) {
		visited[y] = new bool[n];
		for (int x = 0; x < n; x++)
			visited[y][x] = false;
	}

	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	qx.push(x);
	qy.push(y);
	visited[y][x] = true;
	while (!qx.empty() && !qy.empty()) {
		int ux = qx.front(); qx.pop();
		int uy = qy.front(); qy.pop();
		map[uy][ux] = color;
		for (int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < n && map[ny][nx] == 1 && !visited[ny][nx]) {
				qx.push(nx);
				qy.push(ny);
				visited[ny][nx] = true;
			}
		}
	}

	for (int y = 0; y < n; y++)
		delete[] visited[y];
	delete[] visited;
}

int		bfs(int x, int y)
{
	int ans = 100000;
	queue<int> qx;
	queue<int> qy;
	queue<int> qdist;
	bool **visited = new bool*[n];
	for (int y = 0; y < n; y++) {
		visited[y] = new bool[n];
		for (int x = 0; x < n; x++)
			visited[y][x] = false;
	}
	int col = map[y][x];
	visited[y][x] = true;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	qx.push(x);
	qy.push(y);
	qdist.push(0);
	visited[y][x] = true;
	while (!qx.empty() && !qy.empty()) {
		int ux = qx.front(); qx.pop();
		int uy = qy.front(); qy.pop();
		int udist = qdist.front(); qdist.pop();
		if (map[uy][ux] > 1 && map[uy][ux] != col) {
			ans = min(ans, udist);
		}
		for (int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];
			int ndist = udist + 1;
			if (0 <= nx && nx < n && 0 <= ny && ny < n && map[ny][nx] != col && !visited[ny][nx]) {
				qx.push(nx);
				qy.push(ny);
				qdist.push(ndist);
				visited[ny][nx] = true;
			}
		}
	}
	for (int y = 0; y < n; y++)
		delete[] visited[y];
	delete[] visited;
	return ans;
}

int		main(void)
{
	cin >> n;
	map = new int*[n];
	for (int y = 0; y < n; y++) {
		map[y] = new int[n];
		for (int x = 0; x < n; x++)
			cin >> map[y][x];
	}

	/* 각자의 섬을 구분하기 위해 coloring */
	int col = 2;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 1) {
				color(x, y, col++);
			}
		}
	}

	int ans = 100000;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] > 1)
				ans = min(ans, bfs(x, y));
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
