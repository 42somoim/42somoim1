/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10828.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:45:37 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 13:52:38 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int>	list;
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
				cout << "-1\n";
			else
			{
				cout << list.top() << "\n";
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
		else if (!str.compare("top"))
		{
			if (list.empty())
				cout << "-1\n";
			else
				cout << list.top() << "\n";
		}
	}
}