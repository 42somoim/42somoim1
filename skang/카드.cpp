#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    int max;
    long long ret;
    long long arr[100001];
    int cnt;

    max = 1;
    cnt = 1;

    cin >> n;

    for (int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr, arr+n);
    ret=arr[0];
    for (int i=1;i<n;i++)
    {
        if (arr[i] == arr[i-1])
            cnt++;
        else
            cnt=1;
        if (max < cnt)
        {
            max = cnt;
            ret = arr[i];
        }
    }
    printf("%lld\n", ret);
    return (0);
}
