/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   트리의_지름_1967.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:28:39 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/03 11:08:34 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

/* 접근 : 루트를 찾은 후 DFS */

using namespace std;

int n;
map<int, vector<pair<int, int> > > graph;
vector<int> ans;

pair<int, int>		bfs(int v, int sum)
{
	queue<int> q;
	queue<int> qdist;
	int maxDist = 0;
	int maxNode = v;
	bool *visited = new bool[n + 1];
	for (int i = 0; i <= n; i++)
		visited[i] = false;
	q.push(v);
	qdist.push(0);
	visited[v] = true;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		int dist = qdist.front(); qdist.pop();
		if (maxDist < dist) {
			maxNode = u;
			maxDist = dist;
		}
		for (int i = 0; i < graph[u].size(); i++) {
			pair<int, int> p = graph[u][i];
			if (!visited[p.first]) {
				q.push(p.first);
				visited[p.first] = true;
				qdist.push(dist + p.second);
			}
		}
	}
	return make_pair(maxNode, maxDist);
}

int		main(void)
{
	cin >> n;
	int s = 0, e = 0, dist = 0;
	for (int i = 0; i < n - 1; i++) {
			cin >> s >> e >> dist;
			graph[s].push_back(make_pair(e, dist));
			graph[e].push_back(make_pair(s, dist));
	}

	pair<int, int> y = bfs(s, 0);
	pair<int, int> z = bfs(y.first, 0);
	cout << z.second << endl;

	return 0;
}
