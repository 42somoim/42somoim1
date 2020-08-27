/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   제곱수의_합.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 04:45:15 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 05:02:25 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

/*
어케풀지?

1 = 1^2
2 = 1^2 + 1^2
3 = 1^2 + 1^2 + 1^2
4 = 2^2
5 = 2^2 + 1^2
6 = 2^2 + 1^2 + 1^2
7 = 2^2 + 1^2 + 1^2 + 1^2
8 = 2^2 + 2^2
9 = 3^2
10 = 3^2 + 1^2
11 = 3^2 + 1^2 + 1^2
12 = 2^2 + 2^2 + 2^2 = 3^2 + 1^1 + 1^2 + 1^2
13 = 3^2 + 2^2
14 = 3^2 + 2^2 + 1^2
15 = ...

16 = 4^2
32 = 4^2 + 4^2 = 5^2 + 2^2 + 1^2

규칙 : 
- 제곱수인 경우 길이는 1

- 그렇지 않은 경우 d[n - 가장 가까운 제곱수]
=> 잘못 생각함.



*/

//이분 탐색으로 특정 숫자가 제곱수인지 판정
int is_square(int n)
{
	int low;
	int high;

	low = 0;
	high = n;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (mid * mid > n) {
			high = mid - 1;
		} else if (mid * mid < n) {
			low = high + 1;
		} else {
			return (1);
		}
	}
	return (0);
}

int main(void)
{
	int n;
	int *d;
	int square_num;

	cin >> n;
	d = new int[n + 1];

	square_num = 1;
	d[1] = 1;
	for(int i = 2; i <= n; i++) {
		int is_sq = is_square(i);
		if (is_sq) {
			d[i] = 1;
			square_num = i;
		} else {
			d[i] = d[i - square_num] + 1;
		}
	}
	cout << d[n] << endl;
	delete[] d;
}
