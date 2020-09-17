/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   종이의_개수.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:47:52 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/17 17:19:07 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int minus_one = 0, plus_one = 0, zero = 0;

void   solve(int **mat, int x, int y, int size) {
  bool is_filled = true;
  int filled_num = mat[y][x];
  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      if (filled_num != mat[i][j]) {
        is_filled = false;
        break;
      }
    }
  }
  if (is_filled) {
    if (filled_num == -1)
      minus_one++;
    else if (filled_num == 0)
      zero++;
    else
      plus_one++;
  }
  else {
    int dx = size / 3;
    solve(mat, x, y,  dx);
    solve(mat, x, y + dx, dx);
    solve(mat, x, y + 2 * dx, dx);
    solve(mat, x + dx, y, dx);
    solve(mat, x + dx, y + dx, dx);
    solve(mat, x + dx, y + 2 * dx, dx);
    solve(mat, x + 2 * dx, y, dx);
    solve(mat, x + 2 * dx, y + dx, dx);
    solve(mat, x + 2 * dx, y + 2 * dx, dx);
  }
}

int   main(void)
{
  int n;
  cin >> n;
  int **mat = new int*[n];
  for (int i = 0; i < n; i++)
    mat[i] = new int[n];

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      cin >> mat[y][x];
    }
  }
  
  solve(mat, 0, 0, n);
  cout << minus_one << endl;
  cout << zero << endl;
  cout << plus_one << endl;

  for (int i = 0; i < n; i++)
    delete[] mat[i];
  delete[] mat;
  return 0;
}
