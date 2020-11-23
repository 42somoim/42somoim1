/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01168.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:27:25 by kylee             #+#    #+#             */
/*   Updated: 2020/11/09 23:34:45 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

typedef struct		s_node
{
	int				size;
	int				value;
	struct s_node	*left;
	struct s_node	*right;
}					t_node;

t_node				root;
t_node				leaf[100005];
int					leaf_cnt = 0;
int					height;

t_node				*init(int upsize)
{
	t_node			*node;
	int				rightsize = upsize / 2;
	int				leftsize = upsize - rightsize;

	if (upsize == 1)
	{
		leaf[leaf_cnt].left = NULL;
		leaf[leaf_cnt].right = NULL;
		leaf[leaf_cnt].value = leaf_cnt + 1;
		leaf[leaf_cnt].size = 1;
		#if DEBUG
		cout << leaf_cnt << " ";
		#endif
		leaf_cnt++;
		return (&leaf[leaf_cnt - 1]);
	}
	node = (t_node *)malloc(sizeof(t_node));
	if (leftsize)
		node->left = init(leftsize);
	if (rightsize)
		node->right = init(rightsize);
	else
		node->right = NULL;
	node->value = 0;
	node->size = upsize;
	return (node);
}

int				get_num(t_node *node, int now)
{
	int			ret;

	ret = 0;
	if (node->value)
	{
		#if DEBUG
			cout << "[[leaf]]" << "\n";
		#endif 
		node->size = -1;
		return (node->value);
	}
	if (node->left && node->left->size >= now)
	{
		#if DEBUG
			cout << "left" << " ";
		#endif
		ret = get_num(node->left, now);
		if (node->left->size == 0)
		{
			free(node->left);
			node->left = NULL;
		}
	}
	else if (node->left)
	{
		#if DEBUG
			cout << "right" << " ";
		#endif
		ret = get_num(node->right, now - node->left->size);
		if (node->right->size == 0)
		{
			free(node->right);
			node->right = NULL;
		}
	}
	else
	{
		#if DEBUG
			cout << "right" << " ";
		#endif
		ret = get_num(node->right, now);
		if (node->right->size == 0)
		{
			free(node->right);
			node->right = NULL;
		}
	}
	node->size--;
	return (ret);
}

void				joseph(int n, int k)
{
	t_node			*root;
	int				i;
	int				now;

	root = init(n);
	#if DEBUG
	cout << "\n";
	#endif
	now = 1;
	i = 0;
	while (i < n)
	{
		now += k - 1;
		while (now > root->size)
		{
			now -= root->size;
		}
		if (i != n - 1)
			cout << get_num(root, now) << ", ";
		else
			cout << get_num(root, now);
		i++;
	}
}

int		main(void)
{
	int	n;
	int	k;

	cin >> n >> k;
	cout << "<";
	joseph(n, k);
	cout << ">";
}
