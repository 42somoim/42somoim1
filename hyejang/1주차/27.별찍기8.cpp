#include <iostream>

using namespace std;

int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		for (int j = 0; j < 2 * (count - i - 1); j++)
		{
			cout << " ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j <= count - i - 2; j++)
		{
			cout << "*";
		}
		for (int j = 0; j <= (i + 1) * 2 - 1; j++)
		{
			cout << " ";
		}
		for (int j = 0; j <= count - i - 2; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}

