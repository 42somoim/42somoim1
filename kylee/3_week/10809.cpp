/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10809.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:27:13 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:27:23 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int spelling[26] = { -1 };

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string word;
	int stop;
	cin >> word;

	for (int i = 0; i < 26; i++) {
		spelling[i] = -1;
	}
	for (int i = 0; i < word.size(); i++) {
		if (spelling[word[i] - 97] == -1) {
			spelling[word[i] - 97] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << spelling[i] << " ";
	}
	return 0;
}