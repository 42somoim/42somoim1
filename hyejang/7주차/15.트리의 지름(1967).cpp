#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int max_distance; 
int start_node;

void dfs(int start, vector<pair<int, int>> tree[], bool check[], int cost)
{
	check[start] = true;


	for (int i = 0; i < tree[start].size(); i++)
	{
		pair<int, int> next = tree[start][i];
		int nextIndex = next.first; 
		int nextWeight = next.second;

		if (max_distance < cost)
		{
			max_distance = cost;
			start_node = start;
		}

		if (check[nextIndex] == false)
		{
			dfs(nextIndex, tree, check, nextWeight + cost);
		}
	}
}

int main() {

	int tree_count;
	cin >> tree_count;

	vector<pair<int, int>> *tree = new vector<pair<int, int>>[tree_count + 1];

	bool check[100001] = { false };

	for (int i = 0; i < tree_count - 1; i++)
	{
		int tree_number, leaf, cost;
		cin >> tree_number >> leaf >> cost;

		tree[tree_number].push_back(make_pair(leaf, cost));
		tree[leaf].push_back(make_pair(tree_number, cost));
	}

	dfs(1, tree, check, 0);
	fill(check, check + 100001, false);
	dfs(start_node, tree, check, 0);
	cout << max_distance << "\n";
	
	return 0;
}


