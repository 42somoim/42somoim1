#include <iostream>

int main()
{

	long long dp[101];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 100; i++)
		dp[i] = dp[i-2] + dp[i-3];
	int t;
	std::cin >> t;
	while (t--){
		int n;
		std::cin >> n;
		std::cout << dp[n] << '\n';
	}
	return 0;
}
