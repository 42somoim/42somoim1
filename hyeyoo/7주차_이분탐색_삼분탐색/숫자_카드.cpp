/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   숫자_카드.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:26:41 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/11 23:34:09 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

bool binary_search(int *arr, int N, int find)
{
  int low = 0, high = N - 1;
  
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] < find) {
      low = mid + 1;
    } else if (arr[mid] > find) {
      high = mid - 1;
    } else {
      return true;
    }
  }
  return false;
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
    if (binary_search(arr, N, find)) {
      std::cout << "1 ";
    } else {
      std::cout << "0 ";
    }
  }
  std::cout << std::endl;
  return 0;
}
