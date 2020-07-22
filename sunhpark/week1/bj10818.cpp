#include <iostream>
#include <cstdlib>
using namespace std;

int			main(void)
{
	int		num;
	int		cnt;
	int		min, max;

	cin >> cnt;
	min = 1000000;
	max = -1000000;
	while (cnt > 0)
	{
		scanf("%d", &num);
		if (min > num)
			min = num;
		if (max < num)
			max = num;
		cnt--;
	}
	cout << min << " " << max << endl;

	return (0);
}

