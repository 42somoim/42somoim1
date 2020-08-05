/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10814.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:24:34 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:24:44 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct member {
	int age;
	string name;
};
int compare(member a, member b) {
	if (a.age >= b.age) {
		return false;
	}
	else {
		return true;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<member> member_list;
	member mem;
	for (int i = 0; i < n; i++) {
		cin >> mem.age >> mem.name;
		member_list.push_back(mem);
	}

	stable_sort(member_list.begin(), member_list.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << member_list[i].age << " " << member_list[i].name << '\n';
	}
}