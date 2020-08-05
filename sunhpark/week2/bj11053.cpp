#include <iostream>
using namespace std;

int		dp[1001] = {0,};
int		numbers[1001] = {0, };

int		max(int a, int b)
{
	return (a > b ? a : b);
}

int		findSubArr(int	num)
{
	int		ret = 0;
	for (int i = 0; i < num; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if(numbers[i] > numbers[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ret = max(ret, dp[i]);
	}
	return ret;
}

int		main(void)
{
	int		num;

	scanf("%d", &num);
	for(int i = 0; i < num; i++)
	{
		scanf("%d", &numbers[i]);
	}

	printf("%d\n", findSubArr(num));
	
	return (0);
}
