#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	int n, sum = 0;
	int dp[1001], arr[1001];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		sum = max(sum, dp[i]);
	}

	cout << sum << endl;
}