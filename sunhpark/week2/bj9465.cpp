#include <iostream>
using namespace std;

int		dp[2][100001] = {0, };
int		sticker[2][100001] = {0, };

int		max(int	a, int b)
{
	return (a > b ? a : b);
}

void	getSticker(int	n)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &sticker[i][j]);
		}
	}
}

int		findDp(int	n)
{
	dp[0][0] = sticker[0][0];
	dp[1][0] = sticker[1][0];

	dp[0][1] = sticker[0][1] + dp[1][0];
	dp[1][1] = sticker[1][1] + dp[0][0];

	for (int i = 2; i < n; i++)
	{
		dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
		dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
	}

	return (max(dp[0][n - 1], dp[1][n - 1]));
}

int		main(void)
{
	int		tc;
	int		n;

	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> n;
		getSticker(n);
		cout << findDp(n) << endl;
	}

	return (0);
}

