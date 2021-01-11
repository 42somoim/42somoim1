/**
 * 
 * 	02064.cpp
 * 
 * IP 주소 from acmicpc.net
 *
 */

#include <iostream>

using namespace std;

long long		ip[1000];


int		main(void)
{
	int	n;
	int	i, j;
	int	in;
	int	subnet;
	int	flag;
	char	dot;

	cin >> n;
	subnet = 0;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < 4)
		{
			cin >> in;
			printf("a%lld\n", ip[0]);
			ip[i] <<= 8;
			printf("b%lld\n", ip[0]);
			ip[i] |= in;
			if (j != 3)
				cin >> dot;
			j++;
		}
		i++;
	}
	printf("%lld\n", ip[0]);

	i = 0;
	while (i < 32)
	{
		j = 1;
		flag = 0;
		while (j < n)
		{
			if ((ip[0] & (1 << (31 - i))) != (ip[j] & (31 - i)))
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag)
			break ;
		subnet |= (1 << (31 - i));
		i++;
	}

	i = 24;
	while (i >= 0)
	{
		cout << (((ip[0] & subnet) >> i) & 0b11111111);
		if (i != 0)
			cout << ".";
		i -= 8;
	}
	cout << "\n";
	i = 24;
	while (i >= 0)
	{
		cout << (((subnet) >> i) & 0b11111111);
		if (i != 0)
			cout << ".";
		i -= 8;
	}

}
