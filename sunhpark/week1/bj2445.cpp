#include <iostream>
using namespace std;

int			main(void)
{
	int		num;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << "*";
		for (int j = i; j < 2 * (num - 1) - i ; j++)
			cout << " ";
		for (int j = 0; j <= i; j++)
			cout << "*";
		cout << endl;
	}

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i ; j++)
			cout << "*";
		for (int j = 0; j <= 2 * i + 1; j++)
			cout << " ";
		for (int j = 0; j < num - 1 - i; j++)
			cout << "*";
		cout << endl;
	}

	return (0);
}

