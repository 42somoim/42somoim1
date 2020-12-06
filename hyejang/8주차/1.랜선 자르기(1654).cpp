#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K, line[10001] = { 0 };
    long left = 0, right = 2147483647, max_line_length = 0, mid, line_length;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        line[i] = tmp;
    }
    while (1)
    {
        //mid값은 랜선의 길이
        line_length = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < N; i++)
        {
            line_length += line[i] / mid;
        }
        //랜선의 길이가 요구하는 길이보다 더 많을때 왼쪽 left값을 바꾸어서 랜선의 최대길이를 높임  
        if (line_length >= K)
        {
            left = mid + 1;
            max_line_length = max(mid, max_line_length);
            if (left > right)
            {
                break;
            }
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << max_line_length << "\n";
    return 0;
}


