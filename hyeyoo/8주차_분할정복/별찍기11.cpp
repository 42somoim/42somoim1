/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   별찍기11.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:34:39 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/21 19:53:53 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

void fill(string *map, int n, int x, int y, char c)
{
  for (int i = y; i < y + n; i++) {
    for (int j = x; j < x + n; j++) {
      map[i][j] = c;
    }
  }
}

void star(string *map, int n, pair<int, int> from, pair<int, int> to)
{
  /* base case */
  if (n == 3) {
    int x = from.first;
    for (int y = to.second; y >= from.second; y--) {
      map[y][x] = '*';
      x++;
    }

    for (int y = from.second + 1; y <= to.second; y++) {
      map[y][x] = '*';
      x++;
    }

    for (int x = from.first; x <= to.first; x++) {
      map[to.second][x] = '*';
    }
    return ;
  }


  /* 재귀 */
  /* 삼각형1,2,3*/
  star(map, n / 2, make_pair(from.first + n / 2, from.second), make_pair(from.first + n / 2 + n - 2, from.second + n / 2 - 1));
 star(map, n / 2, make_pair(from.first, from.second + n / 2), make_pair(from.first + n - 2, to.second));
 star(map, n / 2, make_pair(from.first + n, from.second + n / 2), make_pair(from.first + n - 2 + n - 1, to.second));
}

int   main(void)
{
  int n;
  cin >> n;
  string map[n];
  for (int i = 0; i < n; i++) {
    map[i].resize(2 * n - 1);
    for (int j = 0; j < 2 * n - 1; j++) {
      map[i][j] = ' ';
    }
  }
  
  star(map, n, make_pair(0, 0), make_pair(2 * n - 2, n - 1));
  for (int i = 0; i < n; i++)
    cout << map[i] << endl;
  return 0;
}
