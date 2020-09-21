#include <iostream>
#include <string.h>

using namespace std;

void	change_char(char *ch)
{
	if (*ch >= 'A' && *ch <= 'Z')
	{
		if ( *ch <= 'Z' - 13 )
			*ch += 13;
		else
			*ch = *ch + 12 - 'Z' + 'A' ;
	}
	else if (*ch >= 'a' && *ch <= 'z')
	{
		if ( *ch <= 'z' - 13 )
			*ch += 13;
		else
			*ch = *ch +  12 - 'z' + 'a';;
	}
	else
		return ;
}

int		main(void)
{
	char	str[100];

	cin.getline(str, 101);
	for (unsigned long int i = 0; i < strlen(str) ; i++)
	{
		change_char(&str[i]);
	}
	printf("%s\n", str);
	return (0);
}

