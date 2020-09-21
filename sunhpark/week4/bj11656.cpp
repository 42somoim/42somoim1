#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using	namespace std;

string	str;

int		main(void)
{
	cin >> str;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int	len = str.length();
	string	rear[len];
	for (int i = 0; i < len; i++)
	{
		rear[i] = str.substr(i, len - i);
	}
	sort(rear, rear + len);
	for (int i = 0; i < len; i++)
	{
		cout << rear[i] << '\n';
	}
	return (0);
}
