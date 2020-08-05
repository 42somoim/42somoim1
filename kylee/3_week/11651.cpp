/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11651.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:24:20 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:24:24 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,x,y;

struct point_s{
	int x;
	int y;
};

bool compare(point_s a, point_s b) {
	if (a.y > b.y) {
		return false;
	}
	else if (a.y < b.y) {
		return true;
	}
	else {
		if (a.x > b.x) {
			return false;
		}
		else if (a.x < b.x){
			return true;
		}
		else {
			return false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	point_s point;
	vector<point_s> list;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		point.x = x;
		point.y = y;
		list.push_back(point);
	}

	sort(list.begin(), list.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << list[i].x << " " << list[i].y << '\n';
 	}
}