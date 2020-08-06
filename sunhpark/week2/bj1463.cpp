#include <iostream>
using namespace std;

int		dp[1000001] = {0,};

int		min(int a, int b)
{
	return (a > b ? b : a);
}

int		findDp(int	n)
{
	if ( n == 1 )
		return 0;
	else if(dp[n] > 0)
		return dp[n];
	else if ( n % 3 == 0 )
	{
		dp[n] = 1 + min(findDp(n - 1), findDp(n / 3));
		return dp[n];
	}
	else if( n % 2 == 0 )
	{
		dp[n] = 1 + min(findDp(n - 1), findDp(n / 2));
		return dp[n];
	}
	{
		dp[n] = 1 + findDp(n - 1);
		return dp[n];
	}
}

int		main(void)
{
	int		n;

	cin >> n;
	cout << findDp(n);

	return (0);
}
