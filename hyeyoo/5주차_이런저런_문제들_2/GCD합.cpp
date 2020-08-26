#include <iostream>

using namespace std;

long long		gcd(long long a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

long long lca(long long a, int b)
{
	if (a < b) {
		long long tmp = a;
		a = b;
		b = tmp;
	}
	return a * b / gcd(a, b);
}

int		main(void)
{
	long long t, n;
	long long a, b;

	cin >> t;
	while (t--) {
		cin >> n;
		long long *arr = new long long[n];
		
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		long long sum = 0;
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << endl;
		delete[] arr;
	}

}
