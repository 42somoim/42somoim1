/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11729.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 19:27:17 by kylee             #+#    #+#             */
/*   Updated: 2020/08/27 19:27:18 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <math.h>
using namespace std;

int tcount = 0;
void move(int, int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n;
	cout << (1<<n) - 1 << '\n';
	tcount = 0;
	move(n, 1, 3);
	//cout << tcount;
}

void move(int n, int start, int end) {
	// n = 1일 때, start에 있던 탑을 end로 옮긴다.
	// n > 1일때, move(n-1)을 실행하고, n번째 블럭을 start, end가 아닌 땅(middle)에 놓은 뒤
	// move(n-1, end, middle)을 실행한다.
	int middle = 0;
	int temp;
	while (start + end + middle != 6) {
		middle++;
	}


	if (n == 1) {
		// start에 있던 탑 1개를 end로 옮긴다.
		tcount++;
		cout << start << " " << end << '\n';
	}
	else {
		move(n - 1, start, middle);
		cout << start << " " << end << '\n';
		move(n - 1, middle, end);

	}
}