#include <iostream>

using namespace std;

int		main(void)
{
    cin.tie(NULL);
	ios::sync_with_stdio(false);

	int month, day, value = 0;

	cin >> month >> day;
	while (month)
	{
		if (month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11)
			value += 31;
		else if (month == 5 || month == 7 || month == 10 || month == 12)
			value += 30;
		else if (month != 1)
			value += 28;
		month--;
	}
	value = (value + day) % 7;
	switch (value)
	{
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	case 0:
		cout << "SUN";
	}
	cout << "\n";
}
