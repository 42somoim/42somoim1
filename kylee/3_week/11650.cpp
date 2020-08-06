/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11650.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:23:53 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:23:53 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {

	int x;
	int y;

};

int n;

bool compare(point a, point b) {
	if (a.x > b.x) {
		return false;
	}
	else if (a.x < b.x) {
		return true;
	}
	else {
		if (a.y > b.y) {
			return false;
		}
		else {
			return true;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<point> point_list;
	cin >> n;
	for (int i = 0; i < n; i++) {
		point point;
		cin >> point.x >> point.y;
		point_list.push_back(point);
	}

	sort(point_list.begin(), point_list.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << point_list[i].x << " " << point_list[i].y << '\n';
	}
}