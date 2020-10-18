#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int		main(void)
{
	char	*num;

	scanf("%s", num);
	int len = strlen(num) - 1;
	int	cnt = 0;
	int n = 0;
	int eight = 0;
	while(len >= 0)
	{
		if (num[len] == '1' && cnt < 3)
			n += pow(2, cnt);
		else if (num[len] == '1')
			eight += pow(2, cnt - 3);
		cnt++;
		len--;
	}
	printf("eight : %d, n : %d\n", eight, n);

	return (0);
}
