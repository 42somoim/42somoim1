#include <stdio.h>

int gcd(int, int);
int lcm(int, int);
int main()
{
    int a, b, n;
	scanf("%d", &n);
	while (n--){
		scanf("%d%d", &a, &b);
		printf("%d\n", lcm(a, b));
	}
    return 0;
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}