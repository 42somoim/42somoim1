#include <iostream>

using namespace std;

int		main(void)
{
	int a, b;

	cin >> a >> b;
	while (a != 0 || b != 0)
	{
		cout << a + b << endl;
		cin >> a >> b;
	}
	return (0);
}
