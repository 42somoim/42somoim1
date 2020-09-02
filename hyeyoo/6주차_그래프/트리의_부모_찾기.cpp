/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   트리의_부모_찾기.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:40:57 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/03 00:52:44 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

int n;
int *parent;
map<int, list<int> > graph;

void	bfs()
{
	int u = 1;
	bool *visited = new bool[n + 1];
	fill_n(visited, false, n + 1);
	queue<int> q;

	q.push(u);
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (list<int>::iterator iter = graph[u].begin(); iter != graph[u].end(); iter++) {
			int v = *iter;
			if (!visited[v]) {
				parent[v] = u;
				q.push(v);
				visited[v] = true;
			}
		}
	}
	delete[] visited;
}

int		main(void)
{
	cin >> n;
	parent = new int[n + 1];

	for (int i = 1; i < n; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	bfs();
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	cout << endl;
	delete[] parent;
	return 0;
}
