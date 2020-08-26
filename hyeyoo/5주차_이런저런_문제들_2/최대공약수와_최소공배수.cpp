#include <iostream>

using namespace std;

int		gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int lca(int a, int b)
{
	if (a < b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	return a * b / gcd(a, b);
}

int		main(void)
{
	int a, b;

	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << lca(a, b) << endl;
}
