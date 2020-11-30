#include <iostream>
#include <string>
#include <queue>
#include <cstring> //memset

using namespace std;

const int MAX = 10000;


int A, B;
bool visited[MAX];

 
string BFS(void)
{
	queue<pair<int, string>> q;
	q.push(make_pair(A, ""));
	visited[A] = true;

	while (!q.empty())
	{
		int num = q.front().first;
		string change = q.front().second;
		q.pop();

		if (num == B)
			return change;
		int curNum = (2 * num) % MAX;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push(make_pair(curNum, change + "D"));
		}

		curNum = (num - 1) < 0 ? 9999 : num - 1;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push(make_pair(curNum, change + "S"));
		}

		curNum = (num % 1000) * 10 + num / 1000;
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push(make_pair(curNum, change + "L"));
		}

		curNum = (num % 10) * 1000 + (num / 10);
		if (!visited[curNum])
		{
			visited[curNum] = true;
			q.push(make_pair(curNum, change + "R"));
		}
	}

}

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		memset(visited, false, sizeof(visited));
		cin >> A >> B;
		cout << BFS() << endl;
	}
	return 0;
}

