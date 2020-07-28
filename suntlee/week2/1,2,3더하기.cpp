#include <iostream>

int main()
{
	int n, t;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		int dp[n+1];
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i < n + 1; i++)
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		std::cout << dp[n] << '\n';
	}
	return 0;
}
