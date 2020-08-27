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
	int		a, b;
	scanf("%d %d", &a, &b);
	
	int		gcd = Gcd(a, b);
	int		lcm = (a * b) / gcd;

	printf("%d\n", gcd);
	printf("%d\n", lcm);

	return (0);
}
