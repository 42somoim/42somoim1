#include <iostream>
#include <cstdlib>
using namespace std;

int			main(void)
{
	int		num;
	int		i;

	i = 1;
	cin >> num;
	while (i <= 9)
	{
		printf("%d * %d = %d\n", num, i, num * i);
		i++;
	}
	return (0);
}

