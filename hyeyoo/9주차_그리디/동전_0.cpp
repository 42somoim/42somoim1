/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   동전_0.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:49:53 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/24 13:54:53 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int     main(void)
{
    int n, k;
    cin >> n >> k;
    int *coin = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (k >= coin[i]) {
            ans += (k / coin[i]);
            k -= coin[i] * (k / coin[i]);
        }
    }
    cout << ans << endl;
    delete[] coin;
    return 0;
}
