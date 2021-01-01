#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, count = 1, top_count = 1;
    long long x, top_num;
    vector<long long> v;
    
    // 테스트 케이스 갯수 받기
    scanf("%d", &N);

    // 케이스 갯수만큼 값 받아 배열에 넣기
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &x); v.push_back(x);
    }
    // 배열 오른차순 정렬
    sort(v.begin(), v.end());

    top_num = v[0];
    // 배열 앞에서부터 검사
    for (int i = 1; i < N; i++)
    {
        if (v[i - 1] == v[i])
        {
            // 순자가 연속으로 나올 경우 count 1 증가
            count++;
            // count가 top_count보다 높은 경우 top_count 업데이트 및 해당 값 top_num에 업데이트
            if (count > top_count)
            {
                top_count = count; top_num = v[i];
            }
        }
        else
            count = 1;
    }
    // 출력
    printf("%lld\n", top_num);
}