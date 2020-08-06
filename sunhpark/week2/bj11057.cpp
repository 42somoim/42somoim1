#include <iostream>
#define mod 10007
using namespace std;

int		dp[1001][10];

long	long	int		findDP(int	n)
{
	long	long	int		sum = 0;

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = dp[i][j] + dp[i - 1][k];
				dp[i][j] = dp[i][j] % mod;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i];
	}

	return (sum % mod);
}

int						main(void)
{
	int						n;

	cin >> n;
	cout << findDP(n) << endl;
	return (0);
};
	
