/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11728.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:27:20 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 12:31:44 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int	list[1000005];
int main(void)
{
	int n, m, i, j, temp;

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	i = 0;
	while (i < n)
		cin >> list[i++];
	i = 0;
	j = 0;
	while (j < m)
	{
		cin >> temp;
		while (i < n && list[i] < temp)
		{
			cout << list[i] << " ";
			i++;
		}
		cout << temp << " ";
		j++;
	}
	while (i < n)
	{
		cout << list[i] << " ";
		i++;
	}
}