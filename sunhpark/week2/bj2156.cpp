#include <iostream>
using namespace std;

int		dp[10001] = {0, };
int		wine[10001] = {0, };

int		max(int a, int b, int c)
{
	int		maxVal = a;
	if (b > maxVal)
		maxVal = b;
	if (c > maxVal)
		maxVal = c;
	return maxVal;
}

void		DP(int n)
{
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for(int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i] + wine[i - 1]);
	}
}

int		main(void)
{
	int		n;
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> wine[i];
		cin.clear();
	}
	DP(n);
	cout << dp[n];

	return (0);
}
