#include <iostream>
using namespace std;

int		dp[11] = {0,};

void	findDp(int n)
{
	if (dp[n] > 0)
		return;
	else
	{
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			if(dp[i] == 0)
			{
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
			}
		}
	}
}

int		main(void)
{
	int	tc;
	int num;

	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> num;
		findDp(num);
		cout << dp[num] << endl;
	}
	return (0);
}
