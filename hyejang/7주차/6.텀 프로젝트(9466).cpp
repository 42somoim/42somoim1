#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;

bool visited[100001]; //방문을 했는지에 대한 여부
bool done[100001]; //방문이 끝났는지 여부
int student[100001];
int cnt;

void dfs(int nodenum, int want[], int N)
{
	visited[nodenum] = true;

	int next = want[nodenum];
	//만약 방문한적이 없다면
	if (visited[next] == false)
	{
		//다음 접전으로 이동
		dfs(next, want, N);
	}
	//그밖에 방문했지만 방문이 끝난 노드가 아니라면 사이클 ??
	else if (!done[next])
	{
		for (int i = next; i != nodenum; i = want[i])
		{
			cnt++;
		}
		cnt++;
	}
	done[nodenum] = true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cnt = 0;

		fill(done, done + 100001, false);
		fill(visited, visited + 100001, false);

		cin >> N;

		for (int j = 1; j <= N; j++)
		{
			cin >> student[j];
		}


		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == false)
			{
				dfs(i, student, N);
			}
		}
		cout << N - cnt << "\n";
	}
	return 0;
}


