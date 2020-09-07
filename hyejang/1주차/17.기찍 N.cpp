#include <iostream>

using namespace std;

int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	cin >> num;
	for (int i = num; num > 0;)
	{
		cout << num-- << "\n";
	}
	return (0);
}