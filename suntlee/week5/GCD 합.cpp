#include <iostream>

int arr[100];
using namespace std;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		long long sum = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				sum += gcd(arr[i], arr[j]);
		cout << sum << '\n';
	}
	return 0;
}

