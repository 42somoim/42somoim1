#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int arr[n];
	int lis[n];
	for (int i = 0; i < n; i++){
		std::cin >> arr[i];
		lis[i] = 1;
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}
	int max = 0;
	for (int i = 0; i < n; i++)
		max = lis[i] > max ? lis[i] : max;
	std::cout << max;
	return 0;
}
	
