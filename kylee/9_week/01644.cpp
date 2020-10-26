/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01644.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:47:16 by kylee             #+#    #+#             */
/*   Updated: 2020/10/14 18:51:07 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int	list[4000005];
int	list2[500000];
int	cnt;

void	check(void)
{
	long long i;
	long long j;

	i = 2;
	while (i <= 4000000)
	{
		if (!list[i])
		{
			list2[cnt++] = i;
			j = i * i;
			while (j <= 4000000)
			{
				list[j] = 1;
				j += i;
			}
		}
		i++;
	}
	return ;
}

int main(void)
{
	int	n;
	int	first, second;
	int	sum;
	int	answer;

	cin >> n;
	first = 0;
	second = 0;
	check();
	sum = 0;
	answer = 0;
	while (second <= cnt)
	{
		//cout << list2[first] << " " << list2[second] <<"\n";
		if (sum < n)
		{
			sum += list2[second++];
			continue ;
		}
		if (sum == n)
		{
			//cout << sum << " " << vt.at(first) << " " << vt.at(second) << "\n";
			answer++;
		}
		sum -= list2[first++];
	}
	cout << answer;
}
