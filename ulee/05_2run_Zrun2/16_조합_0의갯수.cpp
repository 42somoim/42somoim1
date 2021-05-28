#include <iostream>
using namespace std;

int get_primef(int num, int prime)
{
	int ret;

	ret = 0;
	for (long long i = prime; num / i >= 1; i *= prime)
	{
		ret += num / i;
	}
	return (ret);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int n, m;
	int two_prime;
	int five_prime;

	cin >> n >> m;
	two_prime = get_primef(n, 2) - get_primef(n - m, 2) - get_primef(m, 2);
	five_prime = get_primef(n, 5) - get_primef(n - m, 5) - get_primef(m, 5);

	cout << min(two_prime, five_prime) << "\n";
}
