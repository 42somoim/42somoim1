#include <iostream>

int main()
{
	int n;

	std::cin >> n;

	int dp[n+1];
	std::fill_n(dp, n + 1, INT_MAX);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++){
		for (int j = 1; j * j <= i; j++)
			dp[i] = std::min(dp[i], dp[i - j * j] + 1);
	}
	std::cout << dp[n];
	return 0;
}
