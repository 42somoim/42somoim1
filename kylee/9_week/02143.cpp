/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02143.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 19:31:03 by kylee             #+#    #+#             */
/*   Updated: 2020/10/19 00:40:15 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define MAX_HASH (1 << 20)
#define STEP 2317

using namespace std;

typedef long long ll;
int	a[1005];
int	b[1005];

typedef struct	s_hash
{
	ll			value;
	ll			cnt;
}				t_hash;

t_hash	table[MAX_HASH];

void	save_hash(uint n)
{
	uint	key;

	key = n % MAX_HASH;
	while (table[key].cnt)
	{
		if (table[key].value == n)
		{
			table[key].cnt++;
			return ;
		}
		key = (key + STEP) % MAX_HASH;
	}
	table[key].value = n;
	table[key].cnt = 1;
}

ll	find_hash(uint n)
{
	uint	key;

	key = n % MAX_HASH;
	while (table[key].cnt)
	{
		if (table[key].value == n)
			return (table[key].cnt);
		key = (key + STEP) % MAX_HASH;
	}
	return (0);
}

int main(void)
{
	int t;
	int n;
	int m;
	int	i;
	int	j;
	int	temp;
	long long ans;

	cin >> t;
	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> a[i];
		i++;
	}
	cin >> m;
	i = 0;
	while (i < m)
	{
		cin >> b[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = i;
		temp = 0;
		while (j < n)
		{
			temp += a[j];
			save_hash(temp);
			j++;
		}
		i++;
	}
	i = 0;
	ans = 0;
	while (i < m)
	{
		j = i;
		temp = 0;
		while (j < m)
		{
			temp += b[j];
			ans += find_hash(t - temp);
			j++;
		}
		i++;
	}
	cout << ans;
}