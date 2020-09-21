/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   숫자_카드2.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:26:41 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/14 19:42:32 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

int lower_bound(int *arr, int N, int find)
{
  int low = 0, high = N - 1, ans = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] >= find) {
      high = mid - 1;
      ans = mid;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}

int upper_bound(int *arr, int N, int find)
{
  int low = 0, high = N - 1, ans = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] <= find) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int   main(void)
{
  int N, M, find;
  int *arr;

  cin >> N;
  arr = new int[N];
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  sort(arr, arr + N);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> M;
  while (M--) {
    cin >> find;
    int upper = upper_bound(arr, N, find);
    int lower = lower_bound(arr, N, find);
    if (lower == -1) {
      if (arr[lower] == find) {
        std::cout << "1 ";
      } else {
        std::cout << "0 ";
      }
    } else {
      std::cout << (upper - lower + 1) << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}
