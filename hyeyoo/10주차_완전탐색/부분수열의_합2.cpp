#include <iostream>
#include <map>

using namespace std;

int arr[40];
int n, s, middle;
map<int, int> count_sum;
long long ans = 0;

void    left(int i, int sum) {
    if (i == middle) {
        count_sum[sum]++;
        return;
    }
    left(i + 1, sum + arr[i]);
    left(i + 1, sum);
}

void    right(int i, int sum) {
    if (i == n) {
        ans += count_sum[s - sum];
        return;
    }
    right(i + 1, sum + arr[i]);
    right(i + 1, sum);
}

/*
 * 이 문제도 naive하게 가면 2^40이라 안 된다..
 * 이분탐색으로 최적화할 수 있다고 한다. 어떻게?
 *
 * 일단 반으로 나눠봤다.
 *
 * 재귀적으로 풀면 더 줄지 않을까?
 * 불가능.
 */

int     main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    middle = n / 2;
    left(0, 0);
    right(middle, 0);
    if (s == 0)
        ans--;
    cout << ans << endl;
    return 0;
}
