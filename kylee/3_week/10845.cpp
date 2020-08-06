/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10845.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:12:53 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 14:17:02 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<int> list;
int main(void)
{
	int n, input;
	string str;
	cin >> n;
	while (n--)
	{
		cin >> str;
		if (!str.compare("push"))
		{
			cin >> input;
			list.push(input);
		}
		else if (!str.compare("pop"))
		{
			if (list.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << list.front() << "\n";
				list.pop();
			}
		}
		else if (!str.compare("size"))
		{
			cout << list.size() << "\n";
		}
		else if (!str.compare("empty"))
		{
			cout << list.empty() << "\n";
		}
		else if (!str.compare("front"))
		{
			if (list.empty())
				cout << "-1\n";
			else
				cout << list.front() << "\n";
		}
		else if (!str.compare("back"))
		{
			if (list.empty())
				cout << "-1\n";
			else
				cout << list.back() << "\n";
		}
	}
}
