#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100000 + 1;
int V;
bool visited[MAX];
vector<pair<int, int>> graph[MAX];
int diameter = 0;
int farthestNode = 0;

void dfs(int node, int cost)
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
		dfs(graph[node][i].first, cost + graph[node][i].second);
}
 

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> V;

        for (int i = 0; i < V; i++)
        {
			int node;
			cin >> node;
		
			while (1)
			{
				int node2, cost;
				cin >> node2;
				if (node2 == -1)
					break;
				cin >> cost;
				graph[node].push_back({ node2, cost });
			}
        }
        memset(visited, false, sizeof(visited));
        dfs(1, 0);
        memset(visited, false, sizeof(visited));
        diameter = 0;
        dfs(farthestNode, 0);

        cout << diameter << "\n";
        return 0;
}
