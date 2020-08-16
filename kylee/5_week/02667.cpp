/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02667.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:51:26 by kylee             #+#    #+#             */
/*   Updated: 2020/08/12 17:04:46 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int list[30][30][2];
vector<int> result;

int dfs(int i, int j, int n)
{
    int res = 1;
    if (list[i][j][0] == 0 || list[i][j][1] == 1)
        return (0);
    list[i][j][1] = 1;
    if (i > 0)
        res += dfs(i - 1, j, n);
    if (i < n - 1)
        res += dfs(i + 1, j, n);
    if (j > 0)
        res += dfs(i, j - 1, n);
    if (j < n - 1)
        res += dfs(i, j + 1, n);
    return (res);
}

int main(void)
{
    int n;
    int i = 0, j;

    cin >> n;
    while (i < n)
    {
        j = 0;
        string in;
        cin >> in;
        while (j < n)
        {
            list[i][j][0] = in.at(j) - '0';
            j++;
        }
        i++;
    }
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            if (list[i][j][0] == 0) { j++; continue ; }
            if (list[i][j][1] == 0)
            {
                result.push_back(dfs(i, j, n));
            }
            j++;
        }
        i++;
    }
    cout << result.size() << "\n";
    sort(result.begin(), result.end(), greater<int>());
    while (!result.empty())
    {
        cout << result.back() << "\n";
        result.pop_back();
    }
}