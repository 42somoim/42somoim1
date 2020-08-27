/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07576.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:20:03 by kylee             #+#    #+#             */
/*   Updated: 2020/08/12 19:01:42 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

using namespace std;

int list[1005][1005][2];
queue<pair<int, int> > q;

int main(void)
{
    int m, n, i, j, day, change;

    i = 0;
    cin >> m >> n;
    while (i < n)
    {
        j = 0;
        while (j < m)
        {
            cin >> list[i][j][0];
            if (list[i][j][0] == 1)
                q.push(pair<int, int>(i, j));
            j++;
        }
        i++;
    }
    day = 0;
    while (1)
    {
        change = 0;
        i = 0;
        int size;

        size = q.size();
        while (size--)
        {
            i = q.front().first;
            j = q.front().second;
            if (i > 0 && list[i - 1][j][0] == 0)
            {
                q.push(pair<int, int>(i - 1, j));
                list[i - 1][j][0] = 1;
                change = 1;
            }
            if (i < n - 1 && list[i + 1][j][0] == 0)
            {
                q.push(pair<int, int>(i + 1, j));
                list[i + 1][j][0] = 1;
                change = 1;
            }
            if (j > 0 && list[i][j - 1][0] == 0)
            {
                q.push(pair<int, int>(i, j - 1));
                list[i][j - 1][0] = 1;
                change = 1;
            }
            if (j < m - 1 && list[i][j + 1][0] == 0)
            {
                q.push(pair<int, int>(i, j + 1));
                list[i][j + 1][0] = 1;
                change = 1;
            }
            q.pop();
        }
        if (change == 0)
            break ;
        day++;
    }
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < m)
        {
            if (list[i][j][0] == 0)
                change = 1;
            j++;
        }
        i++;
    }
    if (change)
    {
        cout << -1;
        return (0);
    }
    cout << day;
}