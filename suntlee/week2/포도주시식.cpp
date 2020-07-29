#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int arr[n + 1];
	int dp[n + 1];

	for (int i = 1; i <= n; i++)
		std::cin >> arr[i];

	dp[0] = 0, arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];	
	for (int i = 3; i <= n; i++){
		dp[i] = std::max(dp[i-3] + arr[i-1] + arr[i],
				dp[i-2] + arr[i]);
		dp[i] = std::max(dp[i-1], dp[i]);
	}
	std::cout << dp[n];
	return 0;
}

