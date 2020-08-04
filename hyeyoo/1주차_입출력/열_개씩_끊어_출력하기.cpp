#include <iostream>

using namespace std;

int		main(void)
{
	string s;
	getline(cin, s, '\n');

	for(int i = 0; i < s.length(); i++)
	{
		cout << s[i];
		if (i % 10 == 9)
			cout << '\n';
	}
	return (0);
}
