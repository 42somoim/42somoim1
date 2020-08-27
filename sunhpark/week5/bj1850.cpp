#include <iostream>
using namespace std;

long long		Gcd(long long	a, long long b)
{
	if(a % b == 0)
		return b;
	long long r = a % b;
	return Gcd(b, r);
}

int		main(void)
{
	long long		a, b;
	scanf("%lld %lld", &a, &b);
	long long		gcd = Gcd(a, b);
	for(long long i = 0; i < gcd; i++)
	{
		printf("1");
	}
	printf("\n");

	return (0);
}
