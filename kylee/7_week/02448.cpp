/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02448.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 23:15:19 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 19:28:17 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

using namespace std;

queue<int> list;

void cprint(int n, int k)
{
	int i = 0;
	int temp = list.front();
	int flag = 0;
	while (i < 2 * n - k - 1)
	{
		temp = list.front();
		if (i == temp)
		{
			cout << "*";
			list.pop();
			if (k % 3 == 2)
			{
				list.push(i - 1);
				list.push(i + 1);
			}
			else if (k % 3 == 1)
			{
				if (list.back() != i - 1)
					list.push(i - 1);
				list.push(i);
				list.push(i + 1);
			}
			else if (k % 3 == 0)
			{
				if (flag == 0)
				{
					flag = 1;
					list.push(i - 1);
				}
				if (list.front() - i > 2)
				{
					flag = 0;
					list.push(i + 1);
				}
			}
		}
		else
		{
			cout << " ";
		}
		i++;
	}
	if (k % 3 == 0)
		list.push(i);
	while (i++ < 2 * n - 1)
		cout << " ";
	cout << "\n";
	if (k != 0)
		cprint(n, k - 1);
	return ;
}

int main(void)
{
	int n, i;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	i = 0;
	list.push(n - 1);
	cprint(n, n - 1);
}