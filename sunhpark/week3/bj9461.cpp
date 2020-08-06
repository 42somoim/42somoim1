#include <iostream>
using namespace std;

long long int		dp[101] = {0, };

void	Pado(int n)
{
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}
}

int		main(void)
{
	int		tc;
	int		num;

	cin >> tc;
	Pado(100);
	for (int i = 0; i < tc; i++)
	{
		cin >> num;
		cout << dp[num] << endl;
	}
	return (0);

}
