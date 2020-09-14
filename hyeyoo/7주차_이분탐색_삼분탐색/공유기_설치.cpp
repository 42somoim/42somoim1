/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   공유기_설치.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 22:51:49 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/11 23:23:47 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

bool is_possible(long long *arr, long long N, long long C, long long dist)
{
  long long dist_sum = 0;
  long long amount = 1;
  for (long long i = 1; i < N; i++) {
    dist_sum += (arr[i] - arr[i - 1]);
    if (dist_sum >= dist) {
      amount++;
      dist_sum = 0;
    }
  }
  return (amount >= C);
}

long long   solve(long long *arr, long long N, long long C)
{
  long long low = 0, high = arr[N - 1];
  long long ans = 0;

  while (low <= high) {
    long long mid = (low +high) / 2;
    if (is_possible(arr, N, C, mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int    main(void)
{
  long long N, C;
  cin >> N >> C;
  long long *arr = new long long[N];

  for (long long i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + N);
  cout << solve(arr, N, C) << endl;

  return 0;
}
