/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   가장_가까운_두_점.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlim <hyeyoo@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 21:09:03 by chlim             #+#    #+#             */
/*   Updated: 2020/09/21 18:18:44 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

bool comparex(pair<int, int> &a, pair<int, int> &b)
{
  if (a.first < b.first)
    return true;
  else
    return false;
}

bool comparey(pair<int, int> &a, pair<int, int> &b)
{
  if (a.second < b.second)
    return true;
  else
    return false;
}

int power(int x)
{
  return x * x;
}

int get_dist(pair<int, int> x, pair<int, int> y)
{
  return power(x.first - y.first) + power(x.second - y.second);
}
int closest(vector<pair<int, int> > & dots, int from, int to)
{
  int n = to - from + 1;
  int mid = (from + to) / 2;
  /* base case */
  if (n == 1) {
    return INT_MAX;
  } else if (n == 2) {
    return get_dist(dots[0], dots[1]);
  }
 
  int left = closest(dots, from, mid);
  int right = closest(dots, mid + 1, to);
  int ans = min(left, right);
  vector<pair<int, int> > range;

  for (int x = from; x <= to; x++) {
    int dist = dots[x].first - dots[mid].first;
    dist = dist * dist;
    if (dist < ans)
      range.push_back(dots[x]);
  }

  /* left, right의 minimum을 dist로 잡고, dist 안에서 brute force */
  sort(range.begin(), range.end(), comparey);
  for (uint64_t i = 0; i < range.size(); i++) {
    pair<int, int> x = range[i];
    for (uint64_t j = i + 1; j < range.size(); j++) {
      pair<int, int> y = range[j];
      int ydist = power(x.second - y.second);
      if (ydist < ans) {
        int dist = get_dist(x, y);
        ans = min(ans, dist);
      } else {
        break;
      }
    }
  }
  return ans;
}

int   main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  vector<pair<int, int> > dots;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    dots.push_back(make_pair(x, y));
  }
  sort(dots.begin(), dots.end(), comparex);
  cout << closest(dots, 0, n - 1) << endl;

  return 0;
}
