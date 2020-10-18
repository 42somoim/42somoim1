#include <iostream>
#include <string.h>
using	namespace std;

int		location[26];;

int		main(void)
{
	char	str[100];
	cin >> str;
	int		len = strlen(str);

	for (int i = 0; i < 26; i++)
	{
		location[i] = -1;
	}
	
	for (int i = 0; i < len; i++)
	{
		if (location[str[i] - 'a'] >= 0)
			continue;
		else
			location[str[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << location[i] << ' ';
	}
	cout << '\n';
	return (0);
}
