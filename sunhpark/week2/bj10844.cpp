#include <iostream>
using namespace std;

int		dp[101] = {0,};

int		stairNumber(int		n)
{
	if (n == 1)
		return 9;
	else if (dp[n] > 0)
		return dp[n];
	else
	{
		dp[n] = 2 * stairNumber(n - 1) - (n - 1);
		return dp[n];
	}
}

int		main(void)
{
	int		n;

	cin >> n;
	cout << stairNumber(n);

	return 0;
}
