/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11576.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:07:55 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 19:11:01 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;
vector<int> list;
int main(void)
{
	int a, b;
	int m, temp;

	long long conv;

	conv = 0;
	cin >> a >> b >> m;
	while (m--)
	{
		cin >> temp;
		conv *= a;
		conv += temp;
	}
	if (conv == 0)
		cout << 0;
	while (conv)
	{
		list.push_back(conv % b);
		conv /= b;
	}
	while (!list.empty())
	{
		cout << list.back() << " ";
		list.pop_back();
	}
}