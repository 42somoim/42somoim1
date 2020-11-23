#include <iostream>
#include <map>

using namespace std;

int P;
int an, bn;
int A[1000];
int B[1000];
map<int, int> pizza;
int ans = 0;

int     main(void)
{
    cin >> P;
    cin >> an >> bn;
    for (int i = 0; i < an; i++)
        cin >> A[i];
    for (int i = 0; i < bn; i++)
        cin >> B[i];

    /* A에서 선택 안 하는 경우 */
    pizza[0] = 1;
    /* A에서 모두 선택하는 경우 */
    int sum = 0;
    for (int i = 0; i < an; i++)
        sum += A[i];
    pizza[sum] = 1;

    /* 연속된 피자들의 합 */
    /* 어 근데 시계처럼 돌아야 함*/
    for (int start = 0; start < an; start++) {
        sum = 0;
        for (int len = 0; len < an - 1; len++) {
            sum += A[(start + len) % an];
            pizza[sum]++;
        }
    }

    for (int start = 0; start < bn; start++) {
        sum = 0;
        for (int len = 0; len < bn - 1; len++) {
            sum += B[(start + len) % bn];
            ans += pizza[P - sum];
        }
    }

    /* B에서 모두 선택하는 경우 */
    sum = 0;
    for (int i = 0; i < bn; i++)
        sum += B[i];
    ans += pizza[P - sum];
    /* B에서 선택 안 하는 경우 */
    ans += pizza[P];
    cout << ans << endl;
    return 0;
}
