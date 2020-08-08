#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	int dp[n];

	dp[0] = arr[0];
	int ans = dp[0];

	for (int i = 1; i < n; i++){
		dp[i] = std::max(dp[i-1] + arr[i], arr[i]);
		ans = std::max(dp[i], ans);
	}
	std::cout << ans;
}