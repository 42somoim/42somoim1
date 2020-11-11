#include <iostream>
#include <map>

using namespace std;

long long T;
long long A[1000];
long long B[1000];
int a_size;
int b_size;
long long ans;

int     main(void)
{
    map<long long, int> count_sum;
    cin >> T;
    cin >> a_size;
    for (int i = 0; i < a_size; i++)
        cin >> A[i];
    cin >> b_size;
    for (int i = 0; i < b_size; i++)
        cin >> B[i];

    /* A에 대해 가능한 모든 부 배열 */
    for (int i = 0; i < a_size; i++) {
        for (int j = i; j < a_size; j++) {
            long long sum = 0;
            for (int k = i; k <= j; k++) {
                sum += A[k];
            }
            count_sum[sum]++;
        }
    }

    for (int i = 0; i < b_size; i++) {
        for (int j = i; j < b_size; j++) {
            long long sum = 0;
            for (int k = i; k <= j; k++) {
                sum += B[k];
            }
            ans += count_sum[T - sum];
        }
    }
    cout << ans << endl;
    return 0;
}
