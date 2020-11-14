#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void dfs(int num, int T, int *graph)
{
	int sum = 0;
	int tmp = num;

	graph[num]++;

	while (tmp)
	{
		sum += pow(tmp % 10, T);
		tmp /= 10;
	}

	if (graph[sum] == 3)
	{
		return;
	}
	else
	{
		dfs(sum, T, graph);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, T, count = 0;
	int graph[6000001];

	fill(graph, graph + 6000001, 0);
	cin >> A >> T;

	dfs(A, T, graph);

	for (int i = 0; i < 6000001; i++)
	{
		if (graph[i] == 1)
			count++;
	}
	cout << count << "\n";
	return 0;
}


