/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   트리순회.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:19:15 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/03 00:38:31 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define NONE -1

using namespace std;

int 	atoi(char c)
{
	return (c - 'A');
}

char		itoa(int i)
{
	return (i + 'A');
}

void	preorder(int *arr, int node)
{
	int left = (arr[2 * node]);
	int right = (arr[2 * node + 1]);
	cout << itoa(node);
	if (left != NONE)
		preorder(arr, left);
	if (right != NONE)
		preorder(arr, right);
}

void	postorder(int *arr, int node)
{
	int left = (arr[2 * node]);
	int right = (arr[2 * node + 1]);
	if (left != NONE)
		postorder(arr, left);
	if (right != NONE)
		postorder(arr, right);
	cout << itoa(node);
}

void	inorder(int *arr, int node)
{
	int left = (arr[2 * node]);
	int right = (arr[2 * node + 1]);
	if (left != NONE)
		inorder(arr, left);
	cout << itoa(node);
	if (right != NONE)
		inorder(arr, right);
}

int		main(void)
{
	int n;
	cin >> n;
	int *arr = new int[2 * n];
	while (n--) {
		char node, left, right;
		cin >> node >> left >> right;
		node = atoi(node);
		arr[2 * node] = (left == '.') ? -1 : atoi(left);
		arr[2 * node + 1] = (right == '.') ? -1 : atoi(right);
	}
	preorder(arr, 0);
	cout << endl;
	inorder(arr, 0);
	cout << endl;
	postorder(arr, 0);
	cout << endl;
	return 0;
}
