#include <iostream>

using namespace std;

int		main(void)
{
	int month, day;
	int sum;

	sum = 0;
	cin >> month >> day;
	
	for(int i = 1; i < month; i++)
	{
		switch (i)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				sum += 31;
				break;
			case 2:
				sum += 28;
				break;
			default:
				sum += 30;
				break;
		}
	}
	sum += day;
	sum %= 7;
	switch (sum)
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
	cout << endl;
}
