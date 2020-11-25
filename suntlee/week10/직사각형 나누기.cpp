#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<string> a(n);
	
	for(auto& i : a)
		cin >> i;
	
	vector<vector<int>> d(n + 1, vector<int>(m + 1));
	
	for(int i =0; i<n; ++i)
		for(int j =0; j<m; ++j)
			d[i + 1][j + 1] = d[i + 1][j] + d[i][j + 1] - d[i][j] + (a[i][j] & 15);
	
	long long ans = 0;
	
	auto sum = [&](int y1, int x1, int y2, int x2) {
		return d[y2][x2] - d[y2][x1 - 1] - d[y1 - 1][x2] + d[y1 - 1][x1 - 1];
	};

	for(int i =1; i<=n; ++i) {
		for(int j =1; j<=m; ++j) {
			ans = max(ans, 1ll * sum(1, 1, i, j) * sum(1, j + 1, i, m) * sum(i + 1, 1, n, m));
			ans = max(ans, 1ll * sum(1, 1, i, j) * sum(i + 1, 1, n, j) * sum(1, j + 1, n, m));
			ans = max(ans, 1ll * sum(1, 1, i - 1, m) * sum(i, 1, n, j) * sum(i, j + 1, n, m));
			ans = max(ans, 1ll * sum(1, 1, n, j - 1) * sum(1, j, i, m) * sum(i + 1, j, n, m));
		}
	}
	for(int i =1; i<n; ++i)
		for(int j = i + 1; j<n; ++j)
			ans = max(ans, 1ll * sum(1, 1, i, m) * sum(i + 1, 1, j, m) * sum(j + 1, 1, n, m));

	for(int i =1; i<m; ++i)
		for(int j = i + 1; j<m; ++j)
			ans = max(ans, 1ll * sum(1, 1, n, i) * sum(1, i + 1, n, j) * sum(1, j + 1, n, m));

	cout << ans;
	return 0;
}