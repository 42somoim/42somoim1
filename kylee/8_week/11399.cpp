/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11399.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 00:43:59 by kylee             #+#    #+#             */
/*   Updated: 2020/09/08 01:30:55 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int		main(void)
{
	int	n;
	int	i;
	int	temp;
	int	ret;
	vector<int> times;

	cin >> n;
	ret = 0;
	i = 0;
	while (i < n)
	{
		cin >> temp;
		times.push_back(temp);
		i++;
	}
	sort(times.begin(), times.end());
	i = 0;
	while (i < n)
	{
		ret += (i + 1) * times.back();
		times.pop_back();
		i++;
	}
	cout << ret;
}