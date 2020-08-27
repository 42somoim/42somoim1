/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02178.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 00:54:45 by kylee             #+#    #+#             */
/*   Updated: 2020/08/20 00:54:49 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <queue>

using namespace std;

int input[103][103];
int alreadyCheck[103][103];
int dis[103][103];
int n, m;

queue<pair<int, int> > bfs_state;


void bfs(int, int);

int main() {
	cin >> n >> m;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			input[i + 1][j + 1] = (int)temp[j]-48;
 		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << alreadyCheck[i + 1][j + 1];
		}
	}*/
	
	dis[1][1] = 1;
	alreadyCheck[1][1] = 1;
	bfs_state.push(make_pair(1, 1));

	while (bfs_state.size() != 0) {
		bfs(bfs_state.front().first, bfs_state.front().second);
		//cout << bfs_state.front().first << " " << bfs_state.front().second << '\n';
		bfs_state.pop();
	}

	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cout << dis[i + 1][j + 1] << ' ';
		}
		cout << '\n';
	}
	*/
	
	cout << dis[n][m];
}

void bfs(int x, int y) {
	//cout << x << " " << y << '\n';
	pair<int, int> pairs;
	if (x > n || y > m || x < 1 || y < 1) {
		return;
	}

	if (alreadyCheck[x][y + 1] == 0 && input[x][y+1] == 1) {
		alreadyCheck[x][y + 1] = 1;
		dis[x][y + 1] = dis[x][y] + 1;
		bfs_state.push(make_pair(x,y+1));
	}

	if (alreadyCheck[x][y-1] == 0 && input[x][y-1] == 1) {
		alreadyCheck[x][y -1] = 1;
		dis[x][y -1] = dis[x][y] + 1;
		bfs_state.push(make_pair(x, y - 1));
	}

	if (alreadyCheck[x+1][y] == 0 && input[x+1][y] == 1) {
		alreadyCheck[x+1][y] = 1;
		dis[x+1][y] = dis[x][y] + 1;
		bfs_state.push(make_pair(x+1, y));
	}

	if (alreadyCheck[x -1][y] == 0 && input[x - 1][y] == 1) {
		alreadyCheck[x - 1][y] = 1;
		dis[x - 1][y] = dis[x][y] + 1;
		bfs_state.push(make_pair(x-1, y));
	}
}
