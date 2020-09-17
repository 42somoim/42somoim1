/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   별찍기10.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:34:39 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/17 17:46:03 by hyeyoo           ###   ########.fr       */
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

void star(string *map, int n, int x, int y)
{
  if (n == 1) {
    map[y][x] = '*';
  } else {
    int dx = n / 3;
    star(map, dx, x, y);
    star(map, dx, x + dx, y);
    star(map, dx, x + 2 * dx, y);
    star(map, dx, x, y + dx);
    fill(map, dx, x + dx, y + dx, ' ');
    star(map, dx, x + 2 * dx, y + dx);
    star(map, dx, x, y + 2 * dx);
    star(map, dx, x + dx, y + 2 * dx);
    star(map, dx, x + 2 * dx, y + 2 * dx);
  }
}

int   main(void)
{
  int n;
  cin >> n;
  string map[n];
  for (int i = 0; i < n; i++)
    map[i].resize(n);
  

  star(map, n, 0, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << map[i][j];
    }
    cout << endl;
  }
  return 0;
}
