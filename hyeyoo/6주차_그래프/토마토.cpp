/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   토마토.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:08:11 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/03 00:17:54 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

using namespace std;

int w, h;
int **map;

int		bfs()
{
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	queue<int> qx;
	queue<int> qy;
	queue<int> qday;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (map[y][x] == 1) {
				qx.push(x);
				qy.push(y);
				qday.push(0);
			}
		}
	}

	int ans = 0;
	while (!qx.empty() && !qy.empty() && !qday.empty()) {
		int ux = qx.front();
		int uy = qy.front();
		int uday = qday.front();
		qx.pop();
		qy.pop();
		qday.pop();
		ans = max(ans, uday);

		for (int i = 0; i < 4; i++) {
			int nx = ux + dx[i];
			int ny = uy + dy[i];
			int nday = uday + 1;

			if (0 <= nx && nx < w && 0 <= ny && ny < h && map[ny][nx] == 0) {
				qx.push(nx);
				qy.push(ny);
				qday.push(nday);
				map[ny][nx] = 1;
			}
		}
	}

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (map[y][x] == 0)
				return -1;
		}
	}
	return ans;

}

int		main(void)
{
	cin >> w >> h;
	map = new int*[h];
	for (int y = 0; y < h; y++) {
		map[y] = new int[w];
		for (int x = 0; x < w; x++) {
			cin >> map[y][x];
		}
	}
	cout << bfs() << endl;
	return 0;
}
