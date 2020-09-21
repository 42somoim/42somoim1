/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10819.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:41:46 by kylee             #+#    #+#             */
/*   Updated: 2020/09/14 18:16:19 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define MAX_NUM 10
using namespace std;

int				ft_abs(int a)
{
	return ((a > 0) ? a : -a);
}

int				ft_get_value(int *arr, int *arr_set, int max)
{
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	while (i < max - 1)
	{
		ret += ft_abs(arr[arr_set[i]] - arr[arr_set[i + 1]]);
		i++;
	}
	return (ret);
}

int				ft_rec(int *arr, int *arr_set, int max, int index)
{
	int			i;
	int			j;
	int			ret;
	int			temp;
	int			flag;

	flag = 0;
	ret = 0;
	i = 0;
	if (index == max)
	{
		return (ft_get_value(arr, arr_set, max));
	}	
	while (i < max)
	{
		j = 0;
		arr_set[index] = i;
		while (j < index)
		{
			if (arr_set[j] == arr_set[index])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (!flag)
		{
			temp = ft_rec(arr, arr_set, max, index + 1);
			ret = (temp > ret) ? temp : ret;
		}
		else
			flag = 0;
		arr_set[index] = -1;
		i++;
	}
	return (ret);
}

void			ft_init(int *arr, int max)
{
	int			i;

	i = 0;
	while (i < max)
		arr[i++] = -1;
	return ;
}

int				main(void)
{
	int			n;
	int			i;
	int			arr[MAX_NUM];
	int			arr_set[MAX_NUM];
	int			sum;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	i = 0;
	while (i < n)
		cin >> arr[i++];
	ft_init(arr_set, n);
	sum = ft_rec(arr, arr_set, n, 0);
	cout << sum;
	return (0);
}