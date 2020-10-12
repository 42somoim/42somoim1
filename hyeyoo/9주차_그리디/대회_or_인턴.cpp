/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   대회_or_인턴.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:58:54 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/24 14:06:18 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

int     main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    while (k) {
        if (n >= 2 * m) {
            n--;
        } else {
            m--;
        }
        k--;
    }
    cout << std::min(n / 2, m) << endl;
    return 0;
}
