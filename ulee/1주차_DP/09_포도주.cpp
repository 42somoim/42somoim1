#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, wine;
	int value[10001], sum[10001];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> value[i];

	sum[0] = 0;
	sum[1] = value[1];
	sum[2] = value[1] + value[2];
	for (int j = 3; j <= n; j++)
	{
		sum[j] = max(sum[j - 3] + value[j - 1] + value[j], sum[j - 2] + value[j]);
		sum[j] = max(sum[j], sum[j - 1]);
	}

	cout << sum[n];
}
