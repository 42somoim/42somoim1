#include <iostream>

int main()
{
	int t;
	
	std::cin >> t;
	while (t--){
		int n;
		std::cin >> n;

		int arr[2][n];
		long dp[2][n];

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				std::cin >> arr[i][j];
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];
		for (int j = 2; j < n; j++){
			dp[0][j] = std::max(dp[1][j-1], dp[1][j-2]) + arr[0][j];
			dp[1][j] = std::max(dp[0][j-1], dp[0][j-2]) + arr[1][j];
		}
		std::cout << std::max(dp[0][n-1], dp[1][n-1]) << '\n';
	}
	return 0;
}
