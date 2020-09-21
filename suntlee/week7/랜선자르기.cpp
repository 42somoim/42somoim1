#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    long long lan[10001] = {};
    long long max = 0;
    cin >> K >> N;
    
    for (int i = 0; i < K; i++)
        cin >> lan[i];
 
    long long left = 0;
    long long right = LLONG_MAX;
 
    while (left <= right){
        long long mid = (left + right) / 2;
        int result=0;
 
        for (int i = 0; i < K; i++)
            result += lan[i] / mid;
 
        if (result >= N)
        {
            left = mid + 1;
            if (mid > max)
                max = mid;
        }
        else
            right = mid - 1;
 
    }
    cout << max << '\n';
 
    return 0;
}
