#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int dp[n+1][10];

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int j = 2; j < n + 1; j++){
		for (int i = 0; i < 10; i++){
			dp[j][i] = 0;
			for(int k = 0; k <= i; k++){
				dp[j][i] += dp[j-1][k];
				dp[j][i] %= 10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++){
		sum += dp[n][i];
		sum %= 10007;
	}
	std::cout << sum;
	return 0;
}
