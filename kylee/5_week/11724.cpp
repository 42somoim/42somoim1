/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11724.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:42:28 by kylee             #+#    #+#             */
/*   Updated: 2020/08/06 21:54:56 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int list[1005][1005];

int dfs(int i, int n)
{
	int j = 1;
	if (list[i][i] == 0)
		return (0);
	while (j <= n)
	{
		if (list[i][j] == 1)
		{
			list[i][j] = 0;
			list[j][i] = 0;
			dfs(j, n);
		}
		j++;
	}
	return (1);
}

int main(void)
{
	int n, m, i, ret;
	cin >> n >> m;
	while (m--)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		list[temp1][temp2] = 1;
		list[temp2][temp1] = 1;
	}
	i = 0;
	while (i < n)
	{
		list[i + 1][i + 1] = 1;
		i++;
	}
	i = 1;
	ret = 0;
	while (i <= n)
	{
		ret += dfs(i, n);
		i++;
	}
	cout << ret;
}