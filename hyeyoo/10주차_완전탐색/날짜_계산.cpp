#include <iostream>

using namespace std;

int		main(void)
{
	int year = 1;
	int E = 1, S = 1, M = 1;
	int earth, sun, moon;

	cin >> earth >> sun >> moon;
	while ( !(earth == E && sun == S && moon == M) ) {
		E++;
		S++;
		M++;
		if (E == 16)
			E = 1;
		if (S == 29)
			S = 1;
		if (M == 20)
			M = 1;
		year++;
	}
	cout << year << endl;
	return 0;
}
