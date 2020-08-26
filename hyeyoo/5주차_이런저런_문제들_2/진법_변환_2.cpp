#include <iostream>

using namespace std;

string baseChar("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");

void	toBase(int n, int base) {
	if (n >= base)
		toBase(n / base, base);
	cout << baseChar.at(n % base);
}

int		main(void)
{
	int n, base;
	cin >> n >> base;
	toBase(n, base);
	cout << endl;
}

