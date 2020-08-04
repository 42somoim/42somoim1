#include <iostream>

using namespace std;

int		main(void)
{
	int n;

	cin >> n;
	for (int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			cout << " ";
		}
		for(int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}
