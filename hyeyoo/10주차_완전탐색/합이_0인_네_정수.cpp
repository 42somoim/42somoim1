#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long   arr[4000][4];

/*
 * 어떻게 풀지?
 * N이 4000이라 naive하게는 못 푼다.
 * 4000^4는 TLE가 뜰거다.
 *
 * A + B, C + D를 나눠서 생각해보자.
 * 왜 TLE가 뜨지?
 *
 * 이 문제는 시간 제한이 엄청 빡세다..
 * 이분 탐색으로 가자.
 */
int     main(void)
{
    int n;
    long long ans = 0;
    vector<long long> v;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    /* A + B 개수 세기 */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long sum_ab = arr[i][0] + arr[j][1];
            v.push_back(sum_ab);
        }
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long half = arr[i][2] + arr[j][3];
            long long low = lower_bound(v.begin(), v.end(), -half) - v.begin();
            long long high = upper_bound(v.begin(), v.end(), -half) - v.begin();
            if (v[low] == -half)
                ans += (high - low);
        }
    }

    cout << ans << endl;
    return 0;
}
