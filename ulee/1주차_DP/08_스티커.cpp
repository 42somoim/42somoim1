#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int test_case, n; cin >> test_case;
    for (int k = 0; k < test_case; k++)
    {
        cin >> n;
        int value[2][100001], sum[2][100001];
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> value[i][j];
        sum[0][0] = sum[1][0] = 0;
        sum[0][1] = value[0][1];
        sum[1][1] = value[1][1];
        for (int i = 2; i <= n; i++)
        {
            sum[0][i] = max(sum[1][i - 1], sum[1][i - 2]) + value[0][i];
            sum[1][i] = max(sum[0][i - 1], sum[0][i - 2]) + value[1][i];
        }
        cout << max(sum[0][n], sum[1][n]) << endl;
    }
}
