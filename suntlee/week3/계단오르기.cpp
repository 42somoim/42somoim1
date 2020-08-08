#include <iostream>

int main()
{
    int n;
    int arr[301];
    int dp[301];
    scanf("%d", &n);

    arr[0] = 0;
    for (int i = 1; i <= n; i++)
        std::cin >> arr[i];

    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = std::max(arr[1], arr[2]) + arr[3];

    for (int i = 4; i <= n; i++)
        dp[i] = std::max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);

    std::cout << dp[n];#include <iostream>

int main()
{
	int n;
	int arr[301];
	int dp[301];
	scanf("%d", &n);

	arr[0] = 0;
	for (int i = 1; i <= n; i++)
		std::cin >> arr[i];

	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = std::max(arr[1], arr[2]) + arr[3];

	for (int i = 4; i <= n; i++)
		dp[i] = std::max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);

	std::cout << dp[n];

	return 0;

}
