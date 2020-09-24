/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:08:03 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/24 14:27:23 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

int     main(void)
{
    bool has_zero = false;
    vector<int> v;
    int n, digit_sum;
    string in;
    cin >> in;

    digit_sum = 0;
    for (unsigned long i = 0; i < in.size(); i++) {
        int num = in[i] - '0';
        v.push_back(num);
        if (num == 0)
            has_zero = true;
        digit_sum += num;
    }

    if (!has_zero || digit_sum % 3 != 0) {
        cout << -1  << endl;
    } else {
        sort(v.begin(), v.end(), greater<int>());
        string ans;
        for (unsigned int i = 0; i < v.size(); i++) {
            ans.push_back((char)(v[i] + '0'));
        }
        cout << ans << endl;
    }
    return 0;
}
