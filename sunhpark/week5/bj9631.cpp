#include <iostream>
using namespace std;

int		Gcd(int	a, int b)
{
	if(a % b == 0)
		return b;
	int	 r = a % b;
	return Gcd(b, r);
}

int		main(void)
{
	int		T;
	int		gcd = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int	N;
		scanf("%d", &N);
		int		arr[N];
		gcd = 0;
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[j]);
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				gcd += Gcd(arr[j], arr[k]);
			}
		}
		printf("%d\n", gcd);
	}

	return (0);
}
