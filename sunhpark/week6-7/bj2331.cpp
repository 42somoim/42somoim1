#include <iostream>
#include <math.h>
#include <cstring> // memset
using	namespace std;

int 	A, P;
int		visited[1000001];

int		mulsum(int A, int P)
{
	int		ret = 0;

	while (A > 0)
	{
		ret += pow(A % 10, P);
		A /= 10;
	}
	return (ret);
}

void	dfs(int A, int P)
{
	visited[A]++;
	int next = mulsum(A, P);
	if (visited[next] > 2)
		return ;
	dfs(next, P);
}

int		main(void)
{
	int		A, P;
	memset(visited, 0, sizeof(visited));

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> P;
	dfs(A, P);

	int cnt = 0;
	
	for (int i = 0; i < 1000001; i++)
	{
		if (visited[i] == 1)
			cnt++;
	}

	cout << cnt << '\n';
	return (0);
}
