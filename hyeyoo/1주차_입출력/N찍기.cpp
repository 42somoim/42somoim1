#include <iostream>

using namespace std;

int		main(void)
{
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cout << i << '\n';
	}
	return (0);
}
