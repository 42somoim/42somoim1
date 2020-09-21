#include <iostream>
#include <string.h>

using namespace std;

int		ch[27] = {0, };

int		main(void)
{
	char	str[100];
	cin >> str;
	int		len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		int	idx = str[i] - 'a';
		ch[idx]++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << ch[i] << ' ';
	}
	cout << '\n';
	return (0);
}
