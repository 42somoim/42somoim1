#include <iostream>

using namespace std;

int main()
{
	int E, S, M;
	int year = 1;

	cin >> E >> S >> M;

	while (1)
	{
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0)
			break;
		++year;
	}
	cout << year;
	return 0;
}