/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   회의실_배정.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:33:43 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/24 14:51:19 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first <= b.first;
    else
        return a.second < b.second;
}

int     main(void)
{
    int n;
    int end = 0, ans = 0;
    vector<pair<int, int> > meeting;
    cin >> n;

    while (n--) {
        int s, e;
        cin >> s >> e;
        pair<int, int> p = make_pair(s, e);
        meeting.push_back(p);
    }

    sort(meeting.begin(), meeting.end(), compare);
    for (unsigned int i = 0; i < meeting.size(); i++) {
        pair<int, int> p = meeting[i];
        if (p.first >= end) {
            end = p.second;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
