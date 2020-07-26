#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int dp[n+1]; 
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i < n + 1; i++){
		dp[i] = dp[i-1] + 2* dp[i-2];
		dp[i] %= 10007;
	}
	std::cout << dp[n];
	return 0;
}
