#include <iostream>
using namespace std;

long long int		dp[91] = {0,};

void	findNumber(int n)
{
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

int		main(void)
{
	int		n;

	cin >> n;
	findNumber(n);
	cout << dp[n];

	return (0);
}
