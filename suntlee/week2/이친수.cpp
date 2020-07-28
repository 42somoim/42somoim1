#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	long dp[n+1][2];

	dp[1][0] = 0;
	dp[1][1] = 1;
	
	for (int i = 2; i < n + 1; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	std::cout << dp[n][0] + dp[n][1];
	return 0;
}
