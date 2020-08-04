#include<iostream>
#include<algorithm>
using namespace std;

int n, d[1001], a[1001], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                d[i] = max(d[i], d[j] + 1);
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}
