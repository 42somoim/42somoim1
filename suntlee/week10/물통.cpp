#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 200 + 1;
int A, B, C;
bool cache[MAX][MAX][MAX];

vector<int> BFS(void)
{
	queue <pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), C));
	vector<int> result;

	while (!q.empty())
	{
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;

		q.pop();
		if (cache[a][b][c])
			continue;

		cache[a][b][c] = true;
		if (a == 0)
			result.push_back(c);

		if (a + b > B) //넘치면 안되므로
			q.push(make_pair(make_pair(a + b - B, B), c));
		else
			q.push(make_pair(make_pair(0, a + b), c));

		if (a + c > C)
			q.push(make_pair(make_pair(a + b - C, b), C));
		else
			q.push(make_pair(make_pair(0, b), a + c));

		if (b + a > A)
			q.push(make_pair(make_pair(A, b + a - A), c));
		else
			q.push(make_pair(make_pair(b + a, 0), c));

		if (b + c > C)
			q.push(make_pair(make_pair(a, b + c - C), C));
		else
			q.push(make_pair(make_pair(a, 0), b + c));

		if (c + a > A)
			q.push(make_pair(make_pair(A, b), c + a - A));
		else
			q.push(make_pair(make_pair(c + a, b), 0));

		if (c + b > B)
			q.push(make_pair(make_pair(a, B), c + b - B));
		else
			q.push(make_pair(make_pair(a, c + b), 0));
	}
	return result;
}

int main(void)
{
	cin >> A >> B >> C;
	vector<int> result = BFS();
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}
