/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01406.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 14:59:30 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:22:36 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char> l;
int main(void)
{
	string str;
	string input;
	int i = 0, n;

	list<char>::iterator c;
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str >> n;
	while (i < str.size())
	{
		l.push_back(str.at(i));
		i++;
	}
	c = l.end();
	while (n--)
	{
		cin >> input;
		if (!input.compare("L"))
		{
			if (c != l.begin())
				c--;
		}
		else if (!input.compare("D"))
		{
			if (c != l.end())
				c++;
		}
		else if (!input.compare("B"))
		{
			if (c != l.begin())
			{
				list<char>::iterator its;
				its = c;
				its--;
				l.erase(its);
			}
		}
		else if (!input.compare("P"))
		{
			string temp;
			cin >> temp;
			l.insert(c, temp[0]);
		}
	}
	c = l.begin();
	while (c != l.end())
	{
		cout << *c;
		c++;
	}
}