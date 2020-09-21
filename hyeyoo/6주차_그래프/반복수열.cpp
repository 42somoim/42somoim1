/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   반복수열.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:13:48 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/01 18:31:12 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define VISITED_SIZE 1000000

using namespace std;

int		getNext(int num, int p)
{
	int ret = 0;

	while (num > 0) {
		int add = 1;
		int power = p;
		while (power--) {
			add *= (num % 10);
		}
		ret += add;
		num /= 10;
	}
	return ret;
}

int		main(void)
{
	int a, p;
	bool visited[VISITED_SIZE];
	int lenArray[VISITED_SIZE];

	cin >> a >> p;
	for (int i = 0; i < VISITED_SIZE; i++) {
		visited[i] = false;
	}

	int num = a;
	int prev = 0;
	int len = 1;
	int ans = 0;
	while (true) {
		if (visited[num]) {
			ans = lenArray[num] - 1;
			break;
		}
		lenArray[num] = len;
		visited[num] = true;
		prev = num;
		num = getNext(num, p);
		len++;
	}
	cout << ans << endl;
}
