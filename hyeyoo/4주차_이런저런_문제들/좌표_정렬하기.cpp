/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   좌표_정렬하기.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:07:57 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 17:23:26 by hyeyoo           ###   ########.fr       */
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

		bool operator <(Dot &dot) {
			if (x == dot.x) {
				return (y < dot.y);
			} else {
				return (x < dot.x);
			}
		}
};

bool cmp(Dot const &a, Dot const &b) {
			if (a.x == b.x) {
				return (a.y < b.y);
			} else {
				return (a.x < b.x);
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
