/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01991.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:24:18 by kylee             #+#    #+#             */
/*   Updated: 2020/08/12 22:59:58 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

typedef struct	s_node
{
	char		value;
	int			left;
	int			right;
}				t_node;

t_node		list[30];

void	preorder(int n)
{
	cout << (char)(list[n].value + 'A');
	if (list[n].left != -1)
	{
		preorder(list[n].left);
		//cout << char(list[n].left + 'A');
	}
	if (list[n].right != -1)
	{
		preorder(list[n].right);
		//cout << char(list[n].right + 'A');
	}
}

void	inorder(int n)
{
	if (list[n].left != -1)
	{
		inorder(list[n].left);
		//cout << char(list[n].left + 'A');
	}
	cout << (char)(list[n].value + 'A');
	if (list[n].right != -1)
	{
		inorder(list[n].right);
		//cout << char(list[n].right + 'A');
	}
}

void	postorder(int n)
{
	if (list[n].left != -1)
	{
		postorder(list[n].left);
		//cout << char(list[n].left + 'A');
	}
	if (list[n].right != -1)
	{
		postorder(list[n].right);
		//cout << char(list[n].right + 'A');
	}
	cout << (char)(list[n].value + 'A');
}

int main(void)
{
	int		n, i;
	char	input, input1, input2;

	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> input >> input1 >> input2;
		list[input - 'A'].value = input - 'A';
		if (input1 != '.')
			list[input - 'A'].left = input1 - 'A';
		else
			list[input - 'A'].left = -1;
		if (input2 != '.')
			list[input - 'A'].right = input2 - 'A';
		else
			list[input - 'A'].right = -1;
		i++;
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
}