/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   수_정렬하기_3.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:51:29 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 17:55:45 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int count[10000 + 1];
	cin >> n;

	for(int i = 0; i <= 10000; i++)
		count[i] = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		count[num]++;
	}

	for(int i = 1; i <= 10000; i++) {
		while (count[i]--)
			cout << i << '\n';
	}
}
