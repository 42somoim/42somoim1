/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01208.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:15:05 by kylee             #+#    #+#             */
/*   Updated: 2020/10/19 18:10:49 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define MAX_HASH (1 << 23)
#define STEP 2417
#define DEBUG 0
typedef long long ll;

typedef struct		s_hash
{
	ll				value;
	ll				cnt;
}					t_hash;

using namespace std;

t_hash	table[MAX_HASH];
int list[50];

void	save_hash(uint n)
{
	uint	key;

	key = (n % MAX_HASH);
	while (table[key].cnt)
	{
		if (table[key].value == n)
		{
			table[key].cnt++;
			return ;
		}
		key = (n + STEP) % MAX_HASH;
	}
	table[key].value = n;
	table[key].cnt++;
}

ll		find_hash(uint n)
{
	uint	key;

	key = (n % MAX_HASH);
	while (table[key].cnt)
	{
		if (table[key].value == n)
			return (table[key].cnt);
		key = (n + STEP) % MAX_HASH;
	}
	return (0);
}

int main(void)
{
	int n, s;
	int i, j, k;
	long long	sum, ans;

	i = 0;
	ans = 0;
	cin >> n >> s;
	while (i < n)
	{
		cin >> list[i];
		i++;
	}
	i = 0;
	while (i < (1 << (n / 2)))
	{
		j = 0;
		sum = 0;
		while (j < n / 2)
		{
			if (i & (1 << j))
				sum += list[j];
			j++;
		}
		# if DEBUG
		cout << "sum : " << sum << "\n";
		# endif
		save_hash(sum);
		i++;
	}
	i = 0;
	while (i < (1 << (n - n / 2)))
	{
		j = 0;
		sum = 0;
		while (j < (n - n / 2))
		{
			if (i & (1 << j))
				sum += list[j + n / 2];
			j++;
		}
		# if DEBUG
		cout << "sum : " << sum << "\n";
		# endif
		ans += find_hash(s - sum);
		i++;
	}
	
	cout << ((s == 0) ? ans - 1 : ans);
}