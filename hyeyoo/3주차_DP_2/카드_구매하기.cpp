#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int *arr;
    int *d;
    
    cin >> n;
    arr = new int[n +1];
    d = new int[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        d[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        d[i] = arr[i];
        for(int j = 0; j <= i; j++) {
            d[i] = max(d[i], arr[j] + d[i - j]);
        }
    }
    cout << d[n] << endl;
    delete[] arr;
    delete[] d;
}
