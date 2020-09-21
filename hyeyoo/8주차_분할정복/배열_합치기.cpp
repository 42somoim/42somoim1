/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   배열_합치기.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:34:33 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/17 11:44:46 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int   main(void)
{
  int n, m;
  cin >> n >> m;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int *arr1 = new int[n];
  int *arr2 = new int[m];

  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  for (int i = 0; i < m; i++)
    cin >> arr2[i];

  int i = 0, j = 0;
  for (int k = 0; k < n + m; k++) {
    if (i == n) {
      cout << arr2[j] << ' ';
      j++;
    } else if (j == m) {
      cout << arr1[i] << ' ';
      i++;
    } else if (arr1[i] < arr2[j]) {
      cout << arr1[i] << ' ';
      i++;
    } else {
      cout << arr2[j] << ' ';
      j++;
    }
  }
  cout << '\n';
  delete[] arr1;
  delete[] arr2;
  return 0;
}
