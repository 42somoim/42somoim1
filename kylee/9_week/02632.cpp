/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02632.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:27:40 by kylee             #+#    #+#             */
/*   Updated: 2020/10/19 18:04:13 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

/*
int client, nA, nB;
int pizzaA[1000], pizzaB[1000];
int sizeA[1000001] = {}, sizeB[1000001] = {};
int ans = 0;

int main(void)
{
	cin >> client >> nA >> nB;
	for (int i = 0; i < nA; i++)
		cin >> pizzaA[i];
	for (int i = 0; i < nB; i++)
		cin >> pizzaB[i];
	sizeA[0] = 1, sizeB[0] = 1;
	int sum = 0;
	for (int i = 0; i < nA; i++)
		sum += pizzaA[i];
	sizeA[sum]++;
	sum = 0;
	for (int i = 0; i < nB; i++)
		sum += pizzaB[i];
	sizeB[sum]++;
	for (int i = 0;i < nA; i++)
	{
		int sum = 0;
		for (int j = 0; j < nA - 1; j++)
		{
			sum += pizzaA[(i + j) % nA];
			sizeA[sum]++;
		}
	}
	for (int i = 0; i < nB; i++)
	{
		int sum = 0;
		for (int j = 0; j < nB- 1; j++)
		{
			sum += pizzaB[(i + j) % nB];
			sizeB[sum]++;
		}
	}
	for (int i = 0; i <= client; i++)
	{
		ans += (sizeA[i] * sizeB[client - i]);
	}
	cout << ans;
}
*/

int	in1[1001];
int in2[1001];
int	list1[1000001];
int	list2[1000001];

int main(void)
{
	int	t, n, m;
	int	i, j;
	int sum;
	int ans;

	cin >> t >> n >> m;
	i = 0;
	sum = 0;
	list1[0] = 1;
	list2[0] = 1;
	while (i < n)
	{
		cin >> in1[i];
		sum += in1[i];
		i++;
	}
	list1[sum]++;
	i = 0;
	sum = 0;
	while (i < m)
	{
		cin >> in2[i];
		sum += in2[i];
		i++;
	}
	list2[sum]++;
	i = 0;
	while (i < n)
	{
		j = 0;
		sum = 0;
		while (j < n - 1)
		{
			sum += in1[(i + j) % n];
			list1[sum]++;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < m)
	{
		j = 0;
		sum = 0;
		while (j < m - 1)
		{
			sum += in2[(i + j) % m];
			list2[sum]++;
			j++;
		}
		i++;
	}
	ans = 0;
	i = 0;
	while (i <= t)
	{
		ans += (list1[i] * list2[t - i]);
		i++;
	}
	cout << ans;
}

/*
#include <iostream>
#define MAX_HASH (1 << 23)
#define STEP 2317
#define DEBUG 0
#define abs(a) (a > 0 ? a : -a)
#define set(a, b) (a >= 0 ? a : b + a)

using namespace std;

typedef struct		s_hash
{
	int 			value;
	int				cnt;
}					t_hash;

t_hash				hash_table[MAX_HASH];

void				save_hash(uint n)
{
	uint			key;

	key = n % MAX_HASH;
	while (hash_table[key].cnt)
	{
		if (hash_table[key].value == n)
		{
			hash_table[key].cnt++;
			return ;
		}
		key = (key + STEP) % MAX_HASH;
	}
	hash_table[key].cnt = 1;
	hash_table[key].value = n;
	return ;
}

int					find_hash(uint n)
{
	uint			key;

	key = n % MAX_HASH;
	while (hash_table[key].cnt)
	{
		if (hash_table[key].value == n)
			return (hash_table[key].cnt);
		key = (key + STEP) % MAX_HASH;
	}
	return (0);
}

int	list1[1001];
int	list2[1001];
int main(void)
{
	int	t;
	int	n;
	int	m;
	int	i;
	int	j;
	int	sum;
	int	ans;
	int		temp;

	i = 0;
	cin >> t >> n >> m;
	while (i < n)
	{
		cin >> list1[i];
		sum += list1[i];
		i++;
	}
	save_hash(sum);
	save_hash(0);
	i = 0;
	temp = 0;
	while (i < m)
	{
		cin >> list2[i];
		temp += list2[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		sum = 0;
		j = 0;
		while (j < n - 1)
		{
			sum += list1[(i + j) % n];
			# if DEBUG
			cout << "sum : " << sum << "\n";
			# endif 
			if (sum)
				save_hash(sum);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < m)
	{
		sum = 0;
		j = 0;
		while (j < m - 1)
		{
			sum += list2[(i + j) % m];
			# if DEBUG
			cout << "sum3 : " << sum << "\n";
			# endif
			if (sum)
				ans += find_hash(t - sum);
			j++;
		}
		i++;

	}
	ans += find_hash(t - temp);
	ans += find_hash(t);
	# if DEBUG
	cout << find_hash(t) << "\n"; // 왼쪽만 있는 경우
	cout << find_hash(t - temp) << "\n"; // 오른쪽에서 모든 피자를 선택하는 경우
	cout << find_hash(0) << "\n"; // 왼쪽에서 아무것도 선택하지 않음.
	# endif
	cout << ans;
}
*/