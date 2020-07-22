#include <iostream>
#include <cstdlib>
using namespace std;

int			main(void)
{
	int			num;
	int			i, j;

	cin >> num;
	i = 0;
	j = 0;
	while (i < num)
	{
		j = 0;
		while ( j < num - i - 1)
		{
			cout << " ";
			j++;
		}
		while (j < num)
		{
			cout << "*";
			j++;
		}
		cout << endl;
		i++;
	}
	return (0);
}

