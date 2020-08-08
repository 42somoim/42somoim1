#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	if ((n == 0) || (n % 2 == 1))
	{	
		std::cout << 0;
		return 0;
	}
	int dp[n+1];
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i += 2)
	{ 
	  	dp[i] = 3 * dp[i-2];
		for (int j = 4; j < i; j += 2)
			dp[i] += 2 * dp[i-j];
		dp[i] += 2;
	}
	std::cout << dp[n];
	return 0;
}	
