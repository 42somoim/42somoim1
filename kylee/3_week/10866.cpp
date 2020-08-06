/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10866.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:20:40 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 14:28:08 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <queue>
using namespace std;

deque<int> list;
int main(void)
{
	int n, temp;
	string str;
	cin >> n;
	while (n--)
	{
		cin >> str;
		if (!str.compare("push_back"))
		{
			cin >> temp;
			list.push_back(temp);
		}
		else if (!str.compare("push_front"))
		{
			cin >> temp;
			list.push_front(temp);
		}
		else if (!str.compare("pop_front"))
		{
			if (list.empty())
				cout << "-1\n";
			else
			{
				cout << list.front() << "\n";
				list.pop_front();
			}
		}
		else if (!str.compare("pop_back"))
		{
			if (list.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << list.back() << "\n";
				list.pop_back();
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
			{
				cout << list.front() << "\n";
			}
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