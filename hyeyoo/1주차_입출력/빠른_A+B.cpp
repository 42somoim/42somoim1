#include <iostream>

using namespace std;

int		main(void)
{
	int n, a, b;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}

	return (0);
}
