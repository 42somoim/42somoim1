/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04963.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:51:26 by kylee             #+#    #+#             */
/*   Updated: 2020/08/12 17:18:24 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int list[55][55][2];
vector<int> result;

void init(void)
{
    int i = 0;
    int j = 0;
    while (i < 55)
    {
        j = 0;
        while (j < 55)
        {
            list[i][j][0] = 0;
            list[i][j][1] = 0;
            j++;
        }
        i++;
    }
}
int dfs(int i, int j, int x, int y)
{
    int res = 1;
    if (list[i][j][0] == 0 || list[i][j][1] == 1)
        return (0);
    list[i][j][1] = 1;
    if (i > 0)
        res += dfs(i - 1, j, x, y);
    if (i > 0 && j > 0)
        res += dfs(i - 1, j - 1, x, y);
    if (i < y - 1 && j > 0)
        res += dfs(i + 1, j - 1, x, y);
    if (i > 0 && j < x - 1)
        res += dfs(i - 1, j + 1, x, y);
    if (i < y - 1 && j < x - 1)
        res += dfs(i + 1, j + 1, x, y);
    if (i < y - 1)
        res += dfs(i + 1, j, x, y);
    if (j > 0)
        res += dfs(i, j - 1, x, y);
    if (j < x - 1)
        res += dfs(i, j + 1, x, y);
    return (res);
}

int main(void)
{
    int i = 0, j;
    int res = 0;
    int x, y;

    cin >> x >> y;
    while (!(x == 0 && y == 0))
    {
        init();
        res = 0;
        i = 0;
        while (i < y)
        {
            j = 0;
            while (j < x)
            {
                cin >> list[i][j][0];
                j++;
            }
            i++;
        }
        i = 0;
        while (i < y)
        {
            j = 0;
            while (j < x)
            {
                if (list[i][j][0] == 0) { j++; continue ; }
                if (list[i][j][1] == 0)
                {
                    res++;
                    dfs(i, j, x, y);
                }
                j++;
            }
            i++;
        }
        cout << res << "\n";
        cin >> x >> y;
    }
}