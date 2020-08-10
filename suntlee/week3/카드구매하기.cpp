#include <iostream>

int dp[1001];

int main()
{
	int n;
	std::cin >> n;
	
	int card[n+1];
	for (int i = 1; i <= n; i++)
	   std::cin >> card[i];
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = std::max(dp[i], dp[i-j] + card[j]);
	std::cout << dp[n];
	return 0;
}
