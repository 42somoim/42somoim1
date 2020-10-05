#include <iostream>
#include <algorithm>

using namespace std;

int abs(int n)
{
	return (n < 0) ? -n : n;
}

int sum(int *arr, int size)
{
	int sum = 0;
	for (int i = 1; i < size; i++) {
		sum += abs(arr[i - 1] - arr[i]);
	}
	return sum;
}

int		main(void)
{
	int N;
	cin >> N;
	int arr[N];
	int ans = 0;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	do {
		ans = max(ans, sum(arr, N));
	} while (next_permutation(arr, arr + N));
	cout << ans << endl;

	return 0;
}
