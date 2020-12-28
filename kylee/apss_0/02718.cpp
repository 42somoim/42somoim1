/**
 * 
 * 02718.cpp
 * 
 * 타일 채우기 from acmicpc.net
 * 
 **/

#include <iostream>

using namespace std;

int		t;
int		n;
int		list[1001][5];
int		ans[1001];

int		main(void)
{
	int	i;
	int	sum;

	cin >> t;
	i = 0;
	while (i < 1000)
	{
		if (i == 0)
			list[0][0] = 1;
		else
		{
			list[i][0] += list[i - 1][0] + list[i - 1][1] + list[i - 1][2] + list[i - 1][3];
			list[i][1] += list[i - 1][0] + list[i - 1][4];
			list[i][2] += list[i - 1][0] + list[i - 1][3];
			list[i][3] += list[i - 1][0] + list[i - 1][2];
			list[i][4] += list[i - 1][1];
			list[i + 1][0] += list[i - 1][0];
			ans[i - 1] += list[i - 1][0] + list[i - 1][1] + list[i - 1][2] + list[i - 1][3];
			ans[i] += list[i - 1][0];
		}
		i++;
	}
	while (t--)
	{
		cin >> n;
		cout << ans[n - 1] << "\n";
	}
}