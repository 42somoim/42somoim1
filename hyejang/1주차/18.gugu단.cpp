#include <iostream>

using namespace std;

int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;

	cin >> num;
	for (int i = 0; i < 10; i++)
	{
		cout << num << " * " << i + 1 << " = " << num * (i + 1) << endl;
	}
}
