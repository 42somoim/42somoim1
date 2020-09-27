/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   수_묶기.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:03:25 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/27 15:21:08 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int     main(void)
{
    int N;
    vector<int> positive;
    vector<int> negative;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num <= 0) {
            negative.push_back(num);
        } else {
            positive.push_back(num);
        }
    }

    int ans = 0;
    sort(positive.begin(), positive.end());
    while (positive.size() > 0) {
        int a, b;
        if (positive.size() == 1) {
            a = positive.back(); positive.pop_back();
            ans += a;
        } else {
            a = positive.back(); positive.pop_back();
            b = positive.back(); positive.pop_back();
            int add = (a * b > a + b) ? a * b : a + b;
            ans += add;
        }
    }

    sort(negative.begin(), negative.end(), greater<int>());
    while (negative.size() > 0) {
        int a, b;
        if (negative.size() == 1) {
            a = negative.back(); negative.pop_back();
            ans += a;
        } else {
            a = negative.back(); negative.pop_back();
            b = negative.back(); negative.pop_back();
            int add = (a * b > a + b) ? a * b : a + b;
            ans += add;
        }
    }
    cout << ans << endl;
    return 0;
}
