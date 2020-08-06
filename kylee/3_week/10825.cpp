/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10825.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:24:54 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:25:06 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct student {
	string name;
	int korean;
	int english;
	int math;

};

bool compare(student a, student b) {
	if (a.korean == b.korean) {
		if (a.english == b.english) {
			if (a.math == b.math) {
				if (a.name >= b.name) {
					return false;
				}
				else {
					return true;
				}
			}
			else if (a.math > b.math) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (a.english > b.english) {
			return false;
		}
		else {
			return true;
		}
	}
	else if (a.korean > b.korean) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<student> list;
	student stu;
	for (int i = 0; i < n; i++) {
		cin >> stu.name >> stu.korean >> stu.english >> stu.math;
		list.push_back(stu);
	}

	sort(list.begin(), list.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << list[i].name << '\n';
	}
}