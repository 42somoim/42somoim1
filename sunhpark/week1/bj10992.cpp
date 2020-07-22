#include <iostream>
using namespace std;

int			main(void)
{
	int			num;

	cin >> num;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << " ";
		if (i != 0)
			cout << "*";
		cout << endl;
	}
	for (int i = 0; i < 2 * num - 1; i++)
		cout << "*";
	cout << endl;

	return (0);
}
