#include <iostream>

using namespace std;

int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << num + 1<< "\n";
	}
	return (0);
}