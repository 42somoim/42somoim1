#include <iostream>

using namespace std;

int	toTen(string n, int base) {
	int val = 0;
	for (int i = 0; i < n.length(); i++) {
		int add = ('0' <= n.at(i) && n.at(i) <= '9') ? n.at(i) - '0' : n.at(i) - 'A' + 10;
		val = val * base + add;
	}
	return val;
}

int		main(void)
{
	string n;
	int base;

	cin >> n >> base;
	cout << toTen(n, base) << endl;
}

