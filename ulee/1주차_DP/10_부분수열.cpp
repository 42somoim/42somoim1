#include <iostream>
using namespace std;

int main()
{
	int n;
	int arr[1001], sum[1001];

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	sum[1] = 1;
	for (int j = 2; j <= n; j++)
		sum[j] = (arr[j] > arr[j - 1]) ? sum[j - 1] + 1 : sum[j - 1];

	cout << sum[n];
}
