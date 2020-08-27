#include <iostream>
using namespace std;

int		Gcd(int	a, int b)
{
	if(a % b == 0)
		return b;
	int r = a % b;
	return Gcd(b, r);
}

int		main(void)
{
	int 	T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int		a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", (a * b) / Gcd(a, b));
	}

	return (0);
}
