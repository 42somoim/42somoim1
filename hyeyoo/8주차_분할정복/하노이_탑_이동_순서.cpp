/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   하노이_탑_이동_순서.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:59:12 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/17 17:12:02 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

using namespace std;

void  hanoi(int n, int from, int to)
{
  if (n == 1) {
    cout << from << ' ' << to << '\n';
  } else {
    int another = 6 - from - to;
    hanoi(n - 1, from, another);
    hanoi(1, from, to);
    hanoi(n - 1, another, to);
  }
}

int   main(void)
{
  int n;
  cin >> n;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << ((int)pow(2, n) - 1) << '\n';
  hanoi(n, 1, 3);
  return 0;
}
