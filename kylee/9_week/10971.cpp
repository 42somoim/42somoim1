/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10971.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:25:35 by kylee             #+#    #+#             */
/*   Updated: 2020/09/14 18:16:40 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define MAX_NUM 15
using namespace std;

void			ft_show(int *arr_set, int n)
{
	int			i;

	i = 0;
	while (i < n)
		cout << arr_set[i++] << " ";
	cout << "\n";
	return ;
}

int				ft_get_ans(int *arr_set, int arr[][MAX_NUM], int n)
{
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	while (i < n - 1)
	{
		ret += arr[arr_set[i]][arr_set[i + 1]];
		i++;
	}
	ret += arr[arr_set[i]][arr_set[0]];
	return (ret);
}
int				ft_rec(int *arr_set, int arr[][MAX_NUM], int n, int index)
{
	int			i;
	int			j;
	int			ret;
	int			temp;
	int			flag;

	flag = 0;
	ret = 2100000000;
	i = 0;
	if (index == n)
	{
		if (!arr[arr_set[index - 1]][arr_set[0]])
			return (ret);
		return (ft_get_ans(arr_set, arr, n));
	}
	while (i < n)
	{
		j = 0;
		arr_set[index] = i;
		if (index > 0 && !arr[arr_set[index - 1]][i])
			flag = 1;
		while (j < index && !flag)
		{
			if (arr_set[index] == arr_set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (!flag)
		{
			temp = ft_rec(arr_set, arr, n, index + 1);
			ret = (temp > ret) ? ret : temp;
		}
		else
			flag = 0;
		arr_set[index] = -1;
		i++;
	}
	return (ret);
}

void			ft_init(int *arr, int n)
{
	int			i;

	i = 0;
	while (i < n)
		arr[i++] = -1;
	return ;
}

int				main(void)
{
	int			n;
	int			arr[MAX_NUM][MAX_NUM];
	int			i;
	int			j;
	int			arr_set[MAX_NUM];

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			cin >> arr[i][j];
			j++;
		}
		i++;
	}
	ft_init(arr_set, n);
	cout << ft_rec(arr_set, arr, n, 0);
	return (0);
}