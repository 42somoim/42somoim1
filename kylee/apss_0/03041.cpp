/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03041.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:48:27 by kylee             #+#    #+#             */
/*   Updated: 2020/11/12 16:05:47 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int	abs(int a)
{
	return (a > 0 ? a : -a);
}

int main(void)
{
	string in;
	int	i, j;
	int answer;

	i = 0;
	answer = 0 ;
	while (i < 4)
	{
		cin >> in;
		j = 0;
		while (j < 4)
		{
			if (in[j] != '.')
				answer += abs(i - (in[j] - 'A') / 4) + abs(j - (in[j] - 'A') % 4);
			j++;
		}
		i++;
	}
	cout << answer;
}