#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int answer = 0;

void calc(vector<int> &v)
{
	int sum = 0;
	for (int i = 0; i < v.size() - 1; i++)
		sum += abs(v[i] - v[i+1]);
	answer = max(answer, sum);
}

void dfs(int cnt, int n, int *arr, vector<int> &v, bool *selected)
{
	if (cnt == n)
	{
		calc(v);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (selected[i] == true)
			continue;
		selected[i] = true;
		v.push_back(arr[i]);
		dfs(cnt + 1, n, arr, v, selected);
		selected[i] = false;
		v.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;

	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> v;
	bool selected[n] = { false };
	dfs(0, n, arr, v, selected);
	cout << answer;
	return 0;
}