#include <iostream>
using namespace std;

char	Numbers[36] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z'
};

void	numToBase(int n, int b)
{
	if (n / b == 0)
	{
		printf("%c", Numbers[n % b]);
		return ;
	}
	numToBase(n / b, b);
	printf("%c", Numbers[n % b]);
	return ;
}

int		main(void)
{
	int		N, B;
	scanf("%d %d", &N, &B);

	numToBase(N, B);
	printf("\n");
	return (0);
}
