/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02739.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:59:15 by kylee             #+#    #+#             */
/*   Updated: 2020/07/23 22:59:16 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 9; i++) {
		cout << n << " * " << i + 1 << " = " <<  (i + 1) * n << endl;
	}
}