/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05014.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:45:04 by kylee             #+#    #+#             */
/*   Updated: 2020/10/10 16:53:53 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

using namespace std;
queue<int> list;
int	arr[1000005];

int main(void)
{
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	list.push(s);
	arr[s] = 1;
	while (!list.empty())
	{
		if (list.front() == g)
			break ;
		if (list.front() - d > 0 && arr[list.front() - d] == 0)
		{
			list.push(list.front() - d);
			arr[list.front() - d] = arr[list.front()] + 1;
		}
		if (list.front() + u <= f && arr[list.front() + u] == 0)
		{
			list.push(list.front() + u);
			arr[list.front() + u] = arr[list.front()] + 1;
		}

		list.pop();
	}
	if (arr[list.front()] > 0)
		cout << arr[list.front()] - 1;
	else
		cout << "use the stairs";
}