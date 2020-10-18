#include <iostream>

int		N;
int		num[10001];
int		tmp;

int		main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N ; i++)
	{
		scanf("%d", &tmp);
		num[tmp]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < num[i]; j++)
		{
			printf("%d\n", i);
		}
	}
	return (0);
}
