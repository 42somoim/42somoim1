#include <iostream>
#include <algorithm>

using namespace std;

int			dp[1001] = {0, };
int 		N;
int			arr[1001] = {0, };

void		Dp(void)
{
	int		M = 0;
	int		idx = 0;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == arr[i - 1])
		{
			dp[i] = dp[i - 1];
		}
		else
		{
			int j;
			M = -99999;
			for (j = i - 1; j >= 0; j--)
			{
				if(arr[j] == arr[i]) continue;
				if(M < arr[j] && arr[j] < arr[i])
				{
					M = arr[j];
					idx = j;
				}
			}
			dp[i] = arr[i] + dp[idx];
		}
	}
	M = 0;
	for (int i = 1; i <= N; i++)
	{
		if(M < dp[i]) M = dp[i];
	}
	printf("%d\n", M);
}

void		InputValue(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
}

int			main(void)
{
	InputValue();
	Dp();
	return (0);
}
