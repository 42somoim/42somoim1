#include <iostream>
#include <cstring>
using namespace std;

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
	char	*N;
	int		B;
	scanf("%s %d", N, &B);
	printf("%d\n", BaseToDec(N, B));
	return (0);
}
