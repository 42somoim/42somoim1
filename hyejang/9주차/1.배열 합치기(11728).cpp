#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, count;

	cin >> n >> m;
	vector<int> arr(n + m);
	for (int i = 0; i < n + m; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n + m; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}