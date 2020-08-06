/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09012.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:26:38 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:26:39 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> ps;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		bool error = false;
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			if (input[j] == '(') {
				ps.push(1);
			}
			else if (input[j] == ')' && ps.size() != 0) {
				ps.pop();
			}
			else if ( input[j] == ')' && ps.size() == 0){
				error = true;
				break;
			}
		}
		
		if (ps.size()) {
			error = true;
		}

		if (error) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
		}

		while (ps.size()) {
			ps.pop();
		}
	}
}