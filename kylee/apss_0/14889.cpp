/*
**	14889.cpp
**
**	스타트와 링크 from acmicpc.net
*/

#include <iostream>
#include <vector>

#define MIN(a, b) (a > b ? b : a)

using namespace std;

int			list[20][20];

int			abs(int a)
{
	return (a > 0 ? a : -a);
}
int			main(void)
{
	int		n;
	int		i;
	int		j;
	int		k;
	int		sum1;
	int		sum2;
	int		in;
	int		ans;

	cin >> n;
	ans = 9999999;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			cin >> in;
			list[i][j] = in;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < (1 << n))
	{
		j = 0;
		vector<int> s, l;
		//cout << "i : " << i << "\n";
		while (j < n)
		{
			if ((i & (1 << j)))
			{
				//cout << "i, j : " << i << " " << j << "\n";
				s.push_back(j);
			}
			else
				l.push_back(j);
			j++;
		}
		if (s.size() == n / 2 && l.size() == n / 2)
		{
			sum1 = 0;
			sum2 = 0;
		
			j = 0;
			while (j < n / 2)
			{
				k = j + 1;
				while (k < n / 2)
				{
					sum1 += list[s[j]][s[k]] + list[s[k]][s[j]];
					sum2 += list[l[j]][l[k]] + list[l[k]][l[j]];
					k++;
 				}
				j++;
			}
			//cout << i << " " <<  ans << " " << sum1 << " " << sum2 << "\n";
			ans = MIN(ans, abs(sum1 - sum2));
		}
		i++;
	}
	cout << ans;
}