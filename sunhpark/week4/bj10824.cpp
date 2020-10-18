#include <iostream>
#include <string>

using	namespace std;

int	main(void)
{
	int	a, b, c, d;
	cin >> a >> b >> c >> d;

	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(c) + to_string(d);

	long	long n1 = stoll(s1);
	long	long n2 = stall(s2);

	cout << n1 + n2 << '\n';
	return (0);
}

