#include <cstdio>
#include <algorithm>
using namespace std;

//STL 라이브러리 이용
int main()
{
    int n;
    int a[1000001]={};
    
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    sort(a,a+n);
    for (int i=0;i<n;i++)
        printf("%d\n", a[i]);
}

/* 병합 정렬
#include <cstdio>

int a[1000000]; //origin array
int b[1000000]; //temp array

void merge(int start, int end) 
{
    int mid = (start+end)/2;
    int i = start;         // 왼쪽 뭉텅이의 시작 인덱스
    int j = mid+1;         // 오른쪽 뭉텅이의 시작 인덱스
    int k = 0;             // 배열 b의 index로 사용되는 변수

    // 왼쪽집합과 오른쪽집합을 정렬된 상태로 배열 b에 저장하는 것
    while (i <= mid && j <= end) 
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    // 위 과정에서 오른쪽 집합은 b에 모두 옮겨졌는데 왼쪽 집합은 아직 옮겨지지 않은게 남아있다면 b에 마저 옮김
    while (i <= mid)
        b[k++] = a[i++];
    
    // 위 과정에서 왼쪽 집합은 b에 모두 옮겨졌는데 오른쪽 집합은 아직 옮겨지지 않은게 남아있다면 b에 마저 옮김
    while (j <= end)
        b[k++] = a[j++];

    // 정렬된 것을 저장한 배열 b의 값을 원본 배열인 a에 옮김
    for (int i=start; i<=end; i++)
        a[i] = b[i-start];
}

void sort(int start, int end)
{
    if (start == end) //재귀호출 시 재귀호출을 멈추기 위함
        return;

    int mid = (start+end)/2;

    sort(start, mid);
    sort(mid+1, end);
    merge(start, end);
}
int main()
{
    int n;

    scanf("%d", &n);
    for (int i=0; i<n;i++)
        scanf(%d", &a[i]);
    sort(0,n-1);
    for (int i=0; i<n;i++)
        printf("%d\n", a[i]);
    return (0);
}
*/