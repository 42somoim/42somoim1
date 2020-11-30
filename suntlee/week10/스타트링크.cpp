#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000000 + 1;

int F, S, G, U, D;
int cache[MAX];

int BFS(void)
{
	queue<int> q;
	q.push(S);
	cache[S] = 1;

	while (!q.empty())
	{
		int curFloor = q.front();
		q.pop();

		if (curFloor == G)
			return cache[curFloor] - 1;

		int nextFloor[2] = { curFloor + U, curFloor - D };
		for(int i=0; i<2; i++)
			if (1 <= nextFloor[i] && nextFloor[i] <= F && cache[nextFloor[i]]==0)
			{
				cache[nextFloor[i]] = cache[curFloor] + 1;
				q.push(nextFloor[i]);
			}
	}
	return -1;
}

int main(void)
{
	cin >> F >> S >> G >> U >> D;

	int result = BFS();
	if (result == -1)
		cout << "use the stairs" << endl;
	else
		cout << result << endl;
	return 0;
}


