/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   좌표_정렬하기.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:07:57 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 17:24:43 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

class Dot
{
	public:
		int x;
		int y;
		
		Dot(int x, int y) {
			this->x = x;
			this->y = y;
		}

		Dot() { 
		}

		void init(int x, int y) {
			this->x = x;
			this->y = y;
		}
};

bool cmp(Dot const &a, Dot const &b) {
			if (a.y == b.y) {
				return (a.x < b.x);
			} else {
				return (a.y < b.y);
			}
}

int main(void)
{
	int n;
	Dot *dots;

	cin >> n;
	dots = new Dot[n];

	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dots[i].init(x, y);
	}
	sort(dots, dots + n, cmp);

	for(int i = 0; i < n; i++) {
		cout << dots[i].x << ' ' << dots[i].y << '\n';
	}
	delete[] dots;
}
