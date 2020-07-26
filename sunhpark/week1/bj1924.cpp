#include <iostream>
using namespace std;

int			main(void)
{
	int		x, y;
	int		month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int		sum = 0;
	char	day[][7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

	cin >> x >> y;
	for (int i = 0; i < x - 1; i++)
		sum += month[i];
	sum += y;
	cout << day[(sum - 1) % 7];
	return (0);
}
	
