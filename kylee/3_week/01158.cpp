/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01158.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 20:42:57 by kylee             #+#    #+#             */
/*   Updated: 2020/07/28 20:58:35 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

vector<int> list;
int main(void)
{
	int n, k, i, temp;

	i = 0;
	cin >> n >> k;
	while (i < n)
	{
		list.push_back(i + 1);
		i++;
	}
	temp = k - 1;
	cout << "<";
	while(!list.empty())
	{
		if (list.size() != 1)
			cout << list.at(temp % list.size()) << ", ";
		else
		{
			cout << list.at(temp % list.size());
			break ;
		}		
		list.erase(list.begin() + temp % list.size());
		temp = (temp + k - 1) % list.size();
	}
	cout << ">";
}