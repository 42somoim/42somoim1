/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   텀_프로젝트.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:48:10 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/01 19:02:43 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int		getLen(int *arr, int v)
{
	int next = arr[v];
	int ans = 1;

	while (next != v) {
		next = arr[next];
		ans++;
	}
	return ans;
}

int	dfs(int *arr, int *visited, int current, int next, int len, int idx)
{
	if (visited[current])
	{
		if (visited[current] == idx)
			return getLen(arr, current);
		else
			return 0;
	}
	else
	{
		visited[current] = idx;
		int ret = dfs(arr, visited, next, arr[next], len + 1, idx);
		return ret;
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
		int *visited = new int[n + 1];

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			visited[i] = false;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				ans += dfs(arr, visited, i, arr[i], 0, i);
			}
		}
		ans = n - ans;
		cout << ans << endl;
		delete[] arr;
		delete[] visited;
	}
}
