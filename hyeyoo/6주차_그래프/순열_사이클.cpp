/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   순열_사이클.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:48:10 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/01 18:11:43 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool dfs(int *arr, bool *visited, int current, int next)
{
	if (visited[current])
		return true;
	else
	{
		visited[current] = true;
		return dfs(arr, visited, next, arr[next]);
	}
}
int		main(void)
{
	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *arr = new int[n + 1];
		bool *visited = new bool[n + 1];

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			visited[i] = false;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if (dfs(arr, visited, i, arr[i]))
					ans++;
			}
		}
		
		cout << ans << endl;
		delete[] arr;
		delete[] visited;
	}
}
