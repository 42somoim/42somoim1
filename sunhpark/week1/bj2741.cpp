#include <iostream>
#include <cstdlib>
using namespace std;

int			main(void)
{
	int		num;
	int		i;

	i = 1;
	cin >> num;
	while (i <= num)
	{
		printf("%d\n", i);
		i++;
	}
	return (0);
}

