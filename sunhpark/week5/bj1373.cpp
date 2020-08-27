#include <iostream>
#include <cstring>
using namespace std;

char	Numbers[36] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z'
};

void	numToBase(int n, int b)
{
	if (n % b == 0)
	{
		printf("%c", Numbers[n/b]);
		return ;
	}
	if (n / b == 0)
	{
		printf("%c", Numbers[n % b]);
		return ;
	}
	numToBase(n / b, b);
	printf("%c", Numbers[n % b]);
	return ;
}

int		BaseToDec(char *n, int b)
{
	int		ret = 0;
	int		i = 0;
	int		len = strlen(n);
	for(i = 0; i < len; i++)
	{
		if (n[i] >= 'A' && n[i] <= 'Z')
			ret += (n[i] - 55);
		else if(n[i] >= '0' && n[i] <= '9')
			ret += (n[i] - '0');
		if (i != (len - 1))
			ret *= b;
	}
	return ret;
}

int		main(void)
{
	char	str[1000001];
	scanf("%s", str);
	
	int BtD = BaseToDec(str, 2);
	numToBase(BtD, 8);
	printf("\n");
	return (0);
}

