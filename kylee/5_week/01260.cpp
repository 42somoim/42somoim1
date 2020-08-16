/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01260.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 00:50:15 by kylee             #+#    #+#             */
/*   Updated: 2020/08/06 22:39:54 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool		pair_descending(int a, int b);

class graph
{
private:
	int		vertex_count;
	vector<int>	number[1005];
	int		visited[1005];
public:
	graph(int nb)
	{
		int		i;

		i = 0;
		vertex_count = nb;
		while (i < vertex_count)
		{
			visited[i + 1] = 0;
			i++;
		}
	}

	void	add_edge(pair<int, int> edge)
	{
		number[edge.first].push_back(edge.second);
		number[edge.second].push_back(edge.first);
	}

	void	sort_edge()
	{
		int	i;

		i = 0;
		while (i < vertex_count)
		{
			sort(number[i + 1].begin(), number[i + 1].end(), pair_descending);
			i++;
		}
	}

	vector<int>	get_vertex(int nb)
	{
		return (number[nb]);
	}
	
	void	set_vertex_visited(int nb, int vs)
	{
		visited[nb] = vs;
	}

	int		get_vertex_visited(int nb)
	{
		return (visited[nb]);
	}
};

bool		pair_descending(int a, int b)
{
	return (a > b);
}

void		bfs(int nb, graph *graphs, queue<int> *edge_queue)
{
	vector<int>	temp;

	edge_queue->push(nb);
	while (!edge_queue->empty())
	{
		temp = graphs->get_vertex(edge_queue->front());
		graphs->set_vertex_visited(edge_queue->front(), 1);
		cout << edge_queue->front() << " ";
		while (!temp.empty())
		{
			if (graphs->get_vertex_visited(temp.back()) == 0)
			{
				graphs->set_vertex_visited(temp.back(), 1);
				edge_queue->push(temp.back());
			}
			temp.pop_back();
		}
		edge_queue->pop();
	}
}

void		dfs(int nb, graph *graphs)
{
	vector<int>	temp;

	cout << nb << " ";
	graphs->set_vertex_visited(nb, 1);
	temp = graphs->get_vertex(nb);
	while (!temp.empty())
	{
		//cout << nb << " and " << temp.back() << ": " << graphs->get_vertex_visited(nb) << graphs->get_vertex_visited(temp.back()) << "\n";
		if (graphs->get_vertex_visited(temp.back()) == 0)
		{
			dfs(temp.back(), graphs);
		}
		temp.pop_back();
	}
}

int			main(void)
{
	int		n;
	int		m;
	int		v;
	pair<int, int> edge;
	queue<int> edge_queue;

	cin >> n >> m >> v;
	graph	graphs_dfs = graph(n);
	while (m--)
	{
		cin >> edge.first >> edge.second;
		graphs_dfs.add_edge(edge);
	}
	graphs_dfs.sort_edge();
	graph	graphs_bfs = graphs_dfs;
	dfs(v, &graphs_dfs);
	cout << "\n";
	bfs(v, &graphs_bfs, &edge_queue);
}