#include <iostream>
#include <cstdlib>
using namespace std;

int			main(void)
{
	int		num;
	int		i;
	int		sum;

	i = 1;
	sum = 0;
	cin >> num;
	while (i <= num)
	{
		sum += i;
		i++;
	}
	cout << sum << endl;
	return (0);
}

