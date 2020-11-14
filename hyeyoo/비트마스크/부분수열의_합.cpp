#include <iostream>

using namespace std;

int arr[20];

int     main(void)
{
    int n, s, ans;
    cin >> n >> s;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ans = 0;
    for (int subset = 1; subset < (1 << n); subset++) {
        int sum = 0;
        for (int elem = 0; elem < n; elem++) {
            /* if element is in the set */
            if (subset & (1 << elem)) {
                sum += arr[elem];
            }
        }
        if (sum == s)
            ans++;
    }
    cout << ans << endl;
    
    return 0;
}
