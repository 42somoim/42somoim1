#include <iostream>
#include <string>
#include <string.h>

using	namespace	std;

int		Count(char	*str, int	*num)
{
	int	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (islower(str[i]))
			num[0]++;
		else if (isupper(str[i]))
			num[1]++;
		else if (isdigit(str[i]))
			num[2]++;
		else if (isspace(str[i]))
			num[3]++;
	}
	return (0);
}

int		main(void)
{
	char	str[100];
	for (int i = 0; i < 100; i++)
	{
		int		num[4] = {0, };
		cin.getline(str, 101);
		if (!strlen(str))
			return (0);
		Count(str, num);
		cout << num[0] << ' ' <<  num[1] << ' ' <<  num[2] << ' ' << num[3] << '\n';
	}
	return (0);
}
