#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int arr[n];
	int lds[n];
	for (int i = 0; i < n; i++){
		std::cin >> arr[i];
		lds[i] = 1;
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++)
			if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
				lds[i] = lds[j] + 1;
	}
	int max = 0;
	for (int i = 0; i < n; i++)
		max = lds[i] > max ? lds[i] : max;
	std::cout << max;
	return 0;
}