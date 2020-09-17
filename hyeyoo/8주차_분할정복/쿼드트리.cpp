/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   쿼드트리.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:23:36 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/17 17:32:57 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

void compress(string *map, int n, int x, int y)
{
  if (n == 1) {
    cout << map[y][x];
  } else {
    bool is_filled = true;
    char filled_char = map[y][x];
    for (int i = y; i < y + n; i++) {
      for (int j = x; j < x + n; j++) {
        if (filled_char != map[i][j]) {
          is_filled = false;
          break;
        }
      }
    }
    if (is_filled) {
      cout << map[y][x];
    } else {
      int dx = n / 2;
      cout << "(";
      compress(map, dx, x, y);
      compress(map, dx, x + dx, y);
      compress(map, dx, x, y + dx);
      compress(map, dx, x + dx, y + dx);
      cout << ")";
    }
  }
}

int   main(void)
{
  int n;
  cin >> n;
  string map[n];

  for (int i = 0; i < n; i++)
    cin >> map[i];

  compress(map, n, 0, 0);
  cout << '\n';
  return 0;
}
