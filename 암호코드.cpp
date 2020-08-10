#include <iostream>

int dp[5001];

int main()
{
	std::string s;
	std::cin >> s;
	
	int len = s.length();
	int i = 2;
	
	dp[0] = 1;
	dp[1] = 1;
	while (i <= len)
	{
		int x = s[i-1] - '0';
		if (x > 0)
			dp[i] = dp[i-1] % 1000000;
		x = 10 * (s[i-2] - '0') + s[i-1] - '0';
		if (x >= 10 && x <= 26)
			dp[i] = (dp[i] + dp[i-2]) % 1000000;
		i++;
	}
	if (s[0] == '0')
		std::cout << 0;
	else
		std::cout << dp[len];
	return 0;
}
