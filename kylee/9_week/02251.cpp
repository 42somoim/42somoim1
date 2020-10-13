/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02251.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:09:38 by kylee             #+#    #+#             */
/*   Updated: 2020/09/28 19:20:00 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define A(vol) (vol / (201 * 201))
#define B(vol) ((vol % (201 * 201)) / 201)
#define C(vol) (vol % 201)
using namespace std;

int list[8500005];

int abc(int a, int b, int c)
{
	return (201 * 201 * a + 201 * b + c);
}

int fun(queue<int> q, int vol)
{
	if (!list[vol])
	{
		list[vol] = 1;
		q.push(list[vol]);
	}	
	return 1;
}

int main(void)
{
	int a, b, c;
	int	vol;
	queue<int> q;
	vector<int> ans;

	cin >> a >> b >> c;
	vol = c;
	q.push(vol);
	while (!q.empty())
	{
		vol = q.front();
		// B->A
		if (A(vol) == 0)
			ans.push_back(vol % 201);
		list[vol] = 1;
		if (A(vol) + B(vol) + C(vol) != c)
		{
			q.pop();
			continue ;
		}
		if (B(vol) > a - A(vol))
		{
			if (!list[abc(a, B(vol) - a + A(vol), C(vol))])
			{
				list[abc(a, B(vol) - a + A(vol), C(vol))] = 1;
				q.push(abc(a, B(vol) - a + A(vol), C(vol)));
			}
		}
		else
		{
			if (!list[abc(A(vol) + B(vol), 0, C(vol))])
			{
				list[abc(A(vol) + B(vol), 0, C(vol))] = 1;
				q.push(abc(A(vol) + B(vol), 0, C(vol)));	
			}
		}
		// C->A
		if (C(vol) > a - A(vol))
		{
			if (!list[abc(a, B(vol), C(vol) - a + A(vol))])
			{
				list[abc(a, B(vol), C(vol) - a + A(vol))] = 1;
				q.push(abc(a, B(vol), C(vol) - a + A(vol)));
			}
		}
		else
		{
			if (!list[abc(A(vol) + C(vol), B(vol), 0)])
			{
				list[abc(A(vol) + C(vol), B(vol), 0)] = 1;
				q.push(abc(A(vol) + C(vol), B(vol), 0));	
			}
		}

		// A->B
		if (A(vol) > b - B(vol))
		{
			if (!list[abc(A(vol) - b + B(vol), b, C(vol))])
			{
				list[abc(A(vol) - b + B(vol), b, C(vol))] = 1;
				q.push(abc(A(vol) - b + B(vol), b, C(vol)));
			}
		}
		else
		{
			if (!list[abc(0, A(vol) + B(vol), C(vol))])
			{
				list[abc(0, A(vol) + B(vol), C(vol))] = 1;
				q.push(abc(0, A(vol) + B(vol), C(vol)));	
			}
		}
		// C->B
		if (C(vol) > b - B(vol))
		{
			if (!list[abc(A(vol), b, C(vol) - b + B(vol))])
			{
				list[abc(A(vol), b, C(vol) - b + B(vol))] = 1;
				q.push(abc(A(vol), b, C(vol) - b + B(vol)));
			}
		}
		else
		{
			if (!list[abc(A(vol), B(vol) + C(vol), 0)])
			{
				list[abc(A(vol), B(vol) + C(vol), 0)] = 1;
				q.push(abc(A(vol), B(vol) + C(vol), 0));	
			}
		}

		// A->C
		if (A(vol) > c - C(vol))
		{
			if (!list[abc(A(vol) - c + C(vol), B(vol), c)])
			{
				list[abc(A(vol) - c + C(vol), B(vol), c)] = 1;
				q.push(abc(A(vol) - c + C(vol), B(vol), c));
			}
		}
		else
		{
			if (!list[abc(0, B(vol), A(vol) + C(vol))])
			{
				list[abc(0, B(vol), A(vol) + C(vol))] = 1;
				q.push(abc(0, B(vol), A(vol) + C(vol)));	
			}
		}
		// B->C
		if (B(vol) > c - C(vol))
		{
			if (!list[abc(A(vol), B(vol) - c + C(vol), c)])
			{
				list[abc(A(vol), B(vol) - c + C(vol), c)] = 1;
				q.push(abc(A(vol), B(vol) - c + C(vol), c));
			}
		}
		else
		{
			if (!list[abc(A(vol), 0, B(vol) + C(vol))])
			{
				list[abc(A(vol), 0, B(vol) + C(vol))] = 1;
				q.push(abc(A(vol), 0, B(vol) + C(vol)));	
			}
		}
		q.pop();
	}
	sort(ans.begin(), ans.end());
	int i = 0;
	while (i < ans.size())
	{
		if (i != 0 && ans.at(i - 1) != ans.at(i))
			cout << ans.at(i) << " ";
		else if (i == 0)
			cout << ans.at(i) << " ";
		i++;
	}
}