/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATM.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:22:10 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/09/24 15:25:14 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

int     main(void)
{
    int n;
    int *arr;
    cin >> n;
    
    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        ans += sum;
    }
    delete[] arr;
    cout << ans << endl;
    return 0;
}
