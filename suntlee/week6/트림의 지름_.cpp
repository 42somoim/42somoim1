#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 10000 + 1;
int N;
bool visited[MAX];
vector<pair<int, int>> graph[MAX];
int diameter = 0;
int farthestNode = 0;

void DFS(int node, int cost)
{
	if (visited[node])
		return;
	visited[node] = true;
	if (diameter < cost)
	{
		diameter = cost;
		farthestNode = node;
	}
	for (int i = 0; i < graph[node].size(); i++)
		DFS(graph[node][i].first, cost + graph[node][i].second);
}

int main(void)
{

	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;
		graph[node1].push_back(make_pair(node2, cost));
		graph[node2].push_back(make_pair(node1, cost));
	}
	memset(visited, false, sizeof(visited));
	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	diameter = 0;
	DFS(farthestNode, 0);
	cout << diameter << endl;

	return 0;
}