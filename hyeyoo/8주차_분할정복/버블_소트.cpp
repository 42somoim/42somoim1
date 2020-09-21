/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   버블_소트.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlim <hyeyoo@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:02:46 by chlim             #+#    #+#             */
/*   Updated: 2020/09/20 19:51:23 by chlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstdint>
# define SIZE 510000

int64_t arr[SIZE];
int64_t tmp[SIZE];

using namespace std;

int64_t ans = 0;

void merge(int from, int mid, int to)
{
  int idx = from;
  int i = from;
  int j = mid + 1;
  int cnt = 0;
  /* 
     뒤 배열의 것이 앞으로 오면 - 교점이 더 많아짐
     그건 앞 배열의 것을 어딘가에 위치시킬 때 더해준다.
     cnt++ : inversion counting이 될 것들을 증가
     ans += cnt : 교점을 센다.
  */
  while (i <= mid || j <= to) {
    if (i > mid) {
      tmp[idx++] = arr[j++];
      cnt++;
    } else if (j > to) {
      tmp[idx++] = arr[i++];
      ans += cnt;
    } else if (arr[i] <= arr[j]) {
      tmp[idx++] = arr[i++];
      ans += cnt;
    } else {
      tmp[idx++] = arr[j++];
      cnt++;
    }
  }

  for (int i = from; i <= to; i++)
    arr[i] = tmp[i];
}

void merge_sort(int from, int to)
{
  int mid = (to + from) / 2;
  if (from < to) {
    merge_sort(from, mid);
    merge_sort(mid + 1, to);
    merge(from, mid, to);
  }
}

int   main(void)
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  merge_sort(0, n - 1);
  cout << ans << endl;
  return 0;
}
