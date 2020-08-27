/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11725.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:02:12 by kylee             #+#    #+#             */
/*   Updated: 2020/08/16 10:49:15 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int	parent[100005];
vector<int> list[100005];

void dfs(int n)
{
	int i = 0;
	while (i < list[n].size())
	{
		if (parent[list[n].at(i)] != 0) { i++; continue ; }
		parent[list[n].at(i)] = n;
		dfs(list[n].at(i));
		i++;
	}
}
int main(void)
{
	int n, in1, in2, i;
	cin >> n;
	i = 1;
	while (i < n)
	{
		cin >> in1 >> in2;
		list[in1].push_back(in2);
		list[in2].push_back(in1);
		i++;
	}
	dfs(1);
	i = 2;
	while (i <= n)
	{
		cout << parent[i] << "\n";
		i++;
	}
}