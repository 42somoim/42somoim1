#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, K, x;
    vector<int> v;

    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x); v.push_back(x);        
    }
    sort(v.begin(), v.end());
    printf("%d", v[K - 1]);
}