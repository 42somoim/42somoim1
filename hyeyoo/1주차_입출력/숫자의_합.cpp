#include <iostream>

using namespace std;

int		main(void)
{
	int n, sum;
	string s;

	cin >> n;
	sum = 0;
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		sum += (s[i] - '0');
	}
	cout << sum << endl;
	return (0);
}
