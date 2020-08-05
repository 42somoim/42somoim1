#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int arr[n];
	int dp[n];
	for (int i = 0; i < n; i++){
		std::cin >> arr[i];
		dp[i] = 0;
	}
	for (int i = 0; i < n; i++){
		int tmp = 0;
		for (int j = 0; j < i; j++){
			if (arr[i] > arr[j]){
				if (tmp < dp[j])
					tmp = dp[j];
			}
		}
		dp[i] = tmp + arr[i];
	}
	int max = 0;
	for (int i = 0; i < n; i++)
		max = dp[i] > max ? dp[i] : max;
	std::cout << max;
	return 0;
}