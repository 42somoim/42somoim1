/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   민호와_강호.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:53:09 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/14 20:24:56 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

using namespace std;

typedef pair<double, double> P;

double dist(P p1, P p2)
{
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

P move(P from, P to, double p)
{
  return {from.first + (to.first - from.first) * (p / 100), from.second + (to.second - from.second) * (p / 100)};
}

int   main(void)
{
  P minho_from, minho_to, kangho_from, kangho_to;
  cin >> minho_from.first >> minho_from.second;
  cin >> minho_to.first >> minho_to.second;
  cin >> kangho_from.first >> kangho_from.second;
  cin >> kangho_to.first >> kangho_to.second;

  double low = 0, high = 100, p = 0, q = 0, ans = 10e5;
  while (high - low >= 1e-6) {
    p = (2 * low + high) / 3;
    q = (low + 2 * high) / 3;

    P minho_p = move(minho_from, minho_to, p);
    P minho_q = move(minho_from, minho_to, q);
    P kangho_p = move(kangho_from, kangho_to, p);
    P kangho_q = move(kangho_from, kangho_to, q);

    double p_len = dist(minho_p, kangho_p);
    double q_len = dist(minho_q, kangho_q);

    ans = min(ans, min(p_len, q_len));
    if (p_len >= q_len)
      low = p;
    else
      high = q;
  }
  cout.setf(ios::fixed);
  cout.precision(7);
  cout << ans << endl;
  return 0;
}
