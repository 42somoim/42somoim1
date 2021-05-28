#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int arr[101];

int gcd(int a, int  b)
{
	if (a % b == 0)
		return (b);
	return (gcd(b, a % b));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	long long sum;

	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		sum = 0;
		cin >> n;
		for (int j = 0; j < n; ++j) cin >> arr[j];
		for (int k = 0; k < n - 1; ++k)
		{
			for (int l = k + 1; l < n; ++l)
			{
				sum += gcd(arr[k], arr[l]);
			}
		}
		cout << sum << "\n";
	}
	return (0);
}
