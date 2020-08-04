#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int dp[n+1][10] = {0};
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
	dp[1][0] = 0;
	for (int i = 2; i < n + 1; i++)
	{
		dp[i][0] = dp[i-1][1];
		dp[i][9] = dp[i-1][8];
		for (int j = 1; j < 9; j++)
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i];
		sum %= 1000000000;
	}
	std::cout << sum;
	return 0;
}
