/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01707.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:40:10 by kylee             #+#    #+#             */
/*   Updated: 2020/08/06 23:31:22 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

vector<int> list[20005];
int			visit[20005];
int flag = 0;
void check(int s, int n)
{
	if (visit[s] && visit[s] != n)
	{
		flag = 1;
		return ;
	}
	else if (visit[s])
		return ;
	visit[s] = n;
	int i = 0;
	while (i < list[s].size())
	{
		if (n == 2)
			check(list[s].at(i), 1);
		else
			check(list[s].at(i), 2);
		i++;
	}
	return ;
}
void init(void)
{
	int i = 0;
	flag = 0;
	while(i < 20005)
	{
		list[i].clear();
		visit[i] = 0;
		i++;
	}
}
int main(void)
{
	int k, v, e, in1, in2, i;

	cin >> k;
	while (k--)
	{
		i = 1;
		init();
		cin >> v >> e;
		while (e--)
		{
			cin >> in1 >> in2;
			list[in1].push_back(in2);
			list[in2].push_back(in1);
		}
		while (i <= v)
		{
			if (!visit[i])
				check(i, 1);
			i++;
		}
		if (flag > 0)
			cout << "NO\n";
		else
		{
			cout << "YES\n";
		}
		
	}

}