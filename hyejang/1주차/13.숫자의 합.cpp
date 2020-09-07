#include <iostream>

using namespace std;

int		main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num, sum;
	string value;

	cin >> num;
	sum = 0;
	cin >> value;
	for (int i = 0; i < num; i++)
		sum += value[i] - 48;
	cout << sum << "\n";
	return (0);
}
