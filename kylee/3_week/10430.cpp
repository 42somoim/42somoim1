/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10430.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:28:28 by kylee             #+#    #+#             */
/*   Updated: 2020/08/05 16:28:29 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <iomanip>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a + b)%c << endl;
	cout << (a%c + b%c)%c << endl;
	cout << (a * b)%c << endl;
	cout << (a%c * b%c)%c << endl;
}